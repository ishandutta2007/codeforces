#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
int main() {
	int N, M, D;
	cin >> N >> M >> D;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<bool> vis(N, false); vis[0] = true;
	function<void(int)> dfs = [&](int pos) {
		vis[pos] = true;
		for (int i : G[pos]) {
			if (!vis[i]) dfs(i);
		}
	};
	vector<int> dist(N, -1);
	dist[0] = 0;
	queue<int> que;
	vector<int> vl;
	for (int i : G[0]) {
		if (!vis[i]) {
			dfs(i);
			dist[i] = 1;
			que.push(i);
			vl.push_back(i);
		}
	}
	if (D < vl.size() || D > G[0].size()) {
		cout << "NO\n";
	}
	else {
		for (int i : G[0]) {
			if (vl.size() < D && dist[i] == -1) {
				vl.push_back(i);
				que.push(i);
				dist[i] = 1;
			}
		}
		cout << "YES\n";
		for (int i : vl) {
			cout << 1 << ' ' << i + 1 << '\n';
		}
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int i : G[u]) {
				if (dist[i] == -1) {
					dist[i] = dist[u] + 1;
					cout << i + 1 << ' ' << u + 1 << '\n';
					que.push(i);
				}
			}
		}
	}
	return 0;
}