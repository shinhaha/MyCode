#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int indegree[32001] = { 0 };
vector<int> graph[32001];
vector<int> ans;
int n, k;
void bfs() {
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i])
			q.push(i);
	}
	while (!q.empty()) {
		int here = q.top();
		if (!indegree[here])ans.push_back(here);
		q.pop();
		for (int i = 0; i<graph[here].size(); i++) {
			int there = graph[here][i];
			if (!(--indegree[there]))
				q.push(there);
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		indegree[b]++;
		graph[a].push_back(b);
	}
	bfs();
	for (auto it : ans)
		printf("%d ", it);
	return 0;
}