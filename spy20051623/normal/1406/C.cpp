#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int d[100005], sz[100005];
int n;
int mn, ans;
int s;

int dfs1(int p, int f) {
	sz[p] = 1;
	for (int i: g[p]) {
		if (i != f && i != s) sz[p] += dfs1(i, p);
	}
	return sz[p];
}

void dfs2(int p, int f) {
	int mx = n - 1 - sz[p];
	for (int i: g[p]) {
		if (i != f && i != s) mx = max(mx, sz[i]);
	}
	if (mx < mn) {
		mn = mx;
		ans = p;
	}
	for (int i: g[p]) {
		if (i != f && i != s) dfs2(i, p);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) g[i].clear(), d[i] = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		++d[x], ++d[y];
	}
	for (int i = 1; i <= n; ++i) {
		if (d[i] == 1) {
			s = i;
			cout << s << ' ' << g[s][0] << '\n';
			break;
		}
	}
	dfs1(1, 0);
	mn = 1e9;
	dfs2(1, 0);
	cout << s << ' ' << ans << '\n';
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