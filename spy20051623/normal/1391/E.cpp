#include <bits/stdc++.h>

using namespace std;

vector<int> g[500005], v[500005];
int n, m, h, vis[500005];

int dfs(int p, int d) {
	vis[p] = 1;
	if (d >= h) {
		cout << "PATH\n";
		cout << h << '\n';
		cout << p << ' ';
		return 1;
	}
	v[d].push_back(p);
	for (int i: g[p]) {
		if (vis[i]) continue;
		if (dfs(i, d + 1)) {
			cout << p << ' ';
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin >> n >> m;
	h = (n + 1) / 2;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		v[i].clear();
		vis[i] = 0;
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (dfs(1, 1)) {
		cout << '\n';
		return;
	}
	int cnt = 0;
	for (int i = 1; i < h; ++i) {
		cnt += v[i].size() / 2;
	}
	cout << "PAIRING\n";
	cout << cnt << '\n';
	for (int i = 1; i < h; ++i) {
		for (int j = 0; j + 1 < v[i].size(); j += 2) {
			cout << v[i][j] << ' ' << v[i][j + 1] << '\n';
		}
	}
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