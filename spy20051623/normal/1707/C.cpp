#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
const int N = 1e5 + 5;
int fa[N], tag[N], dep[N], f[N][20], c[N << 1], ans[N];
pii e[N << 1];
std::vector<int> g[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int p, int x) {
	for (int i: g[p]) {
		if (i == x) continue;
		f[i][0] = p;
		dep[i] = dep[p] + 1;
		dfs(i, p);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	int d = dep[x] - dep[y] - 1;
	for (int i = 0; i < 20; ++i) {
		if (d >> i & 1) x = f[x][i];
	}
	if (f[x][0] == y) return x;
	x = f[x][0];
	for (int i = 19; i >= 0; --i) {
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return x;
}

void cal(int p, int x, int s) {
	if (s <= 0) ans[p] = 1;
	for (int i: g[p]) {
		if (i == x) continue;
		cal(i, p, s + tag[i]);
	}
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		e[i].first = x;
		e[i].second = y;
		if (find(x) != find(y)) {
			fa[find(y)] = find(x);
			g[x].push_back(y);
			g[y].push_back(x);
		} else {
			c[i] = 1;
		}
	}
	dfs(1, 0);
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	for (int i = 0; i < m; ++i) {
		if (c[i]) {
			int x = e[i].first, y = e[i].second;
			int l = lca(x, y);
			if (f[l][0] == x) {
				++tag[l];
				--tag[y];
			} else if (f[l][0] == y) {
				++tag[l];
				--tag[x];
			} else {
				++tag[1];
				--tag[x];
				--tag[y];
			}
		}
	}
	cal(1, 0, tag[1]);
	for (int i = 1; i <= n; ++i) {
		std::cout << ans[i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}