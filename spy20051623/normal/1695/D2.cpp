#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (n == 1) {
		cout << "0\n";
		return;
	}
	int p;
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() == 1) {
			p = i;
			break;
		}
	}
	vector<int> f(n + 1);
	function<void(int, int)> dfs1 = [&](int p, int fa) {
		if (g[p].size() > 2) f[p] = 1;
		for (int i: g[p]) {
			if (i == fa) continue;
			dfs1(i, p);
			if (f[i]) f[p] = 1;
		}
	};
	dfs1(p, 0);
	int ans = 0;
	function<void(int, int, int)> dfs2 = [&](int p, int fa, int c) {
//		cerr << p << "\n";
		if (g[p].size() == 1) {
			++ans;
			return;
		}
		if (g[p].size() == 2) {
			if (g[p][0] == fa) dfs2(g[p][1], p, c);
			else dfs2(g[p][0], p, c);
			return;
		}
		int x = 1;
		for (int i: g[p]) {
			if (i == fa) continue;
			if (!x || f[i] || !c) dfs2(i, p, 1);
			else x = 0;
		}
	};
	dfs2(g[p][0], p, 0);
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}