#include <bits/stdc++.h>

using namespace std;

int fa[400005], c[400005];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		fa[i + n] = n + i;
		c[i] = c[i + n] = 0;
	}
	bool ok = true;
	for (int i = 0; i < m; ++i) {
		int x, y;
		string s;
		cin >> x >> y >> s;
		if (s[0] == 'i') {
			if (find(x) == find(y) || find(x + n) == find(y + n)) ok = false;
			fa[find(y + n)] = find(x);
			fa[find(y)] = find(x + n);
		} else {
			if (find(x) == find(y + n) || find(x + n) == find(y)) ok = false;
			fa[find(y)] = find(x);
			fa[find(y + n)] = find(x + n);
		}
	}
	if (!ok) {
		cout << -1 << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i) ++c[find(i)];
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += max(c[i], c[i + n]);
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