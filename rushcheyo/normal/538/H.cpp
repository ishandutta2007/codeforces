#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, T, n, m, l[N], r[N], fa[N];
bool faw[N];
char ans[N];

void gg() { cout << "IMPOSSIBLE\n"; exit(0); }

int find(int x) {
	if (!fa[x]) return x;
	int t = find(fa[x]);
	faw[x] ^= faw[fa[x]];
	return fa[x] = t;
}
void link(int u, int v) {
	int s = find(u), t = find(v);
	if (s == t) {
		if (faw[u] == faw[v]) gg();
		return;
	}
	faw[s] = faw[u] ^ faw[v] ^ 1, fa[s] = t;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> t >> T >> n >> m;
	int maxl = 0, minr = 1000000000;
	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> r[i], maxl = max(maxl, l[i]), minr = min(minr, r[i]);
	if (maxl + minr < t) maxl = t - minr;
	else if (maxl + minr > T) minr = T - maxl;
	if (minr < 0 || maxl < 0) gg();
	for (int i = 1, x, y; i <= m; ++i) cin >> x >> y, link(x, y);
	for (int i = 1; i <= n; ++i) {
		bool b1 = maxl >= l[i] && maxl <= r[i], b2 = minr >= l[i] && minr <= r[i];
		if (!b1 && !b2) gg();
		int z = b1 ^ b2 ? b2 : -1;
		if (z == -1) continue;
		find(i);
		if (!fa[i]) {
			if (ans[i] && ans[i] != '1' + z) gg();
			ans[i] = '1' + z;
		} else {
			z ^= faw[i];
			int x = fa[i];
			if (ans[x] && ans[x] != '1' + z) gg();
			ans[x] = '1' + z;
		}
	}
	cout << "POSSIBLE\n" << maxl << ' ' << minr << '\n';
	for (int i = 1; i <= n; ++i) if (find(i) == i && !ans[i]) ans[i] = '1';
	for (int i = 1; i <= n; ++i) {
		find(i);
		if (fa[i]) ans[i] = '1' + (faw[i] ^ ans[fa[i]] - '1');
	}
	cout << ans + 1 << '\n';
	return 0;
}