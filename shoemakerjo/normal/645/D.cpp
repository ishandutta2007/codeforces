#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> path; //the singular path in the thing
	int spots[n+1]; //maps me to my index in the path
	int dir = 0; //number direct seen

	int indeg[n+1];
	fill(indeg, indeg+n+1, 0);
	int u, v;
	vector<pii> edges;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		indeg[v]++;
		edges.push_back(pii(u, v));
	}
	
	bool ok = true;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		if (q.size() > 1) {
			ok = false;
			break;
		}
		u = q.front(); q.pop();
		path.push_back(u);
		for (auto v : adj[u]) {
			indeg[v]--;
			if (indeg[v] == 0) q.push(v);
		}
	}

	for (int i = 0; i < path.size(); i++) {
		spots[path[i]] = i;
	}

	if (!ok) {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < m; i++) {
			u = edges[i].first;
			v = edges[i].second;
			if (spots[v] == spots[u]+1) {
				dir++;
			}
			if (dir == n-1) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	cin >> n;

}