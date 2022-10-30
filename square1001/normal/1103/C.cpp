#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y; --x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<int> d(N), p(N), leaf;
	vector<bool> vis(N);
	function<void(int, int)> dfs = [&](int pos, int pre) {
		p[pos] = pre;
		vis[pos] = true;
		bool isleaf = true;
		for (int i : G[pos]) {
			if (vis[i]) continue;
			d[i] = d[pos] + 1;
			dfs(i, pos);
			isleaf = false;
		}
		if (isleaf) leaf.push_back(pos);
	};
	dfs(0, -1);
	int maxd = *max_element(d.begin(), d.end());
	if (maxd >= (N + K - 1) / K) {
		vector<int> path;
		int cur = max_element(d.begin(), d.end()) - d.begin();
		path.push_back(cur);
		while (cur != 0) {
			cur = p[cur];
			path.push_back(cur);
		}
		cout << "PATH" << '\n';
		cout << path.size() << '\n';
		for (int i = 0; i < path.size(); ++i) {
			if (i) cout << ' ';
			cout << path[i] + 1;
		}
		cout << '\n';
	}
	else {
		cout << "CYCLES" << '\n';
		for (int i = 0; i < K; ++i) {
			int u = leaf[i];
			vector<int> vlist;
			for (int j : G[u]) {
				if (j == p[u]) continue;
				vlist.push_back(j);
			}
			if ((d[u] - d[vlist[1]]) % 3 != 2) swap(vlist[0], vlist[1]);
			vector<int> cycle;
			if ((d[u] - d[vlist[0]]) % 3 != 2) {
				cycle.push_back(u);
				int cur = u;
				while (cur != vlist[0]) {
					cur = p[cur];
					cycle.push_back(cur);
				}
			}
			else {
				if (d[vlist[0]] < d[vlist[1]]) swap(vlist[0], vlist[1]);
				cycle.push_back(u);
				int cur = vlist[0];
				cycle.push_back(cur);
				while (cur != vlist[1]) {
					cur = p[cur];
					cycle.push_back(cur);
				}
			}
			cout << cycle.size() << '\n';
			for (int j = 0; j < cycle.size(); ++j) {
				if (j) cout << ' ';
				cout << cycle[j] + 1;
			}
			cout << '\n';
		}
	}
	return 0;
}