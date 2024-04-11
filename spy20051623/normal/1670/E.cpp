#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	n = 1 << n;
	vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
	vector<int> node(n + 1), edge(n + 1), vis(n + 1);
	for (int i = 1; i <= n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back(i, y);
		g[y].emplace_back(i, x);
	}
	int cnt = 1;
	function<void(int)> dfs = [&](int p) {
		for (pair<int, int> i: g[p]) {
			if (vis[i.first]) continue;
			vis[i.first] = 1;
			if (node[p] >= n) edge[i.first] = cnt | n, node[i.second] = cnt, ++cnt;
			else edge[i.first] = cnt, node[i.second] = cnt | n, ++cnt;
			dfs(i.second);
		}
	};
	node[1] = n;
	dfs(1);
	cout << "1\n";
	for (int i = 1; i <= n; ++i) cout << node[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= n - 1; ++i) cout << edge[i] << ' ';
	cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}