#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	bool getComple = false; 
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		graph[--x].push_back(--y);
		graph[y].push_back(x);
		if ((x == 0 && y == n - 1) || (x == n - 1 && y == 0)) {
			getComple = true;
		}
	}
	if (getComple) {
		vector<vector<int>> newGraph(n, vector<int>());
		for (int i = 0; i < n; ++i) {
			set<int> adjSet(graph[i].begin(), graph[i].end());
			for (int j = 0; j < n; ++j) {
				if (j != i && adjSet.count(j) == 0) {
					newGraph[i].push_back(j);
				}
			}
		}
		graph = newGraph;
	}
	vector<int> dist(n, -1);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (int neigh : graph[c]) {
			if (dist[neigh] == -1) {
				dist[neigh] = dist[c] + 1;
				q.push(neigh);
			}
		}
	}
	cout << dist[n-1] << endl;
	return 0;
}