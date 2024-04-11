#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<vector<int>> graph(n, vector<int>());
	vector<vector<int>> rev = graph;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x; scanf("%d", &x);
			if (x > 0) {
				graph[i].push_back(j);
				rev[j].push_back(i);
			}
		}
	}
	vector<bool> visited(n, false);
	vector<bool> rvisit(n, false);
	visited[0] = true;
	rvisit[0] = true;
	queue<int> q;
	q.push(0);
	//printf("done with input\n");
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int neigh : graph[cur]) {
			if (!visited[neigh]) {
				visited[neigh] = true;
				q.push(neigh);
			}
		}
	}
	q.push(0);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int neigh : rev[cur]) {
			if (!rvisit[neigh]) {
				rvisit[neigh] = true;
				q.push(neigh);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!visited[i] || !rvisit[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}