#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 2; i <= n; ++i) {
		int f;
		cin >> f;
		g[f].push_back(i);
	}
	string s;
	cin >> s;
	int ans = 0;
	function<int(int)> dfs = [&](int p) {
		int x = s[p - 1] == 'W' ? 1 : -1;
		for (int i: g[p]) x += dfs(i);
		if (!x) ++ans;
		return x;
	};
	dfs(1);
	cout << ans << '\n';
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