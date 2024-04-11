#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;
const int N = 1e5 + 5;
std::vector<pii> g[N];
int fa[N], dep[N], st[20][N];
pii f[20][N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int p, int x) {
	for (pii i: g[p]) {
		if (i.first == x) continue;
		f[0][i.first].first = p;
		f[0][i.first].second = i.second;
		dep[i.first] = dep[p] + 1;
		dfs(i.first, p);
	}
}

int qry(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	int d = dep[x] - dep[y];
	int ans = 0;
	for (int i = 0; i < 20; ++i) {
		if (d >> i & 1) {
			ans = std::max(ans, f[i][x].second);
			x = f[i][x].first;
		}
	}
	if (x == y) return ans;
	for (int i = 19; i >= 0; --i) {
		if (f[i][x].first != f[i][y].first) {
			ans = std::max(ans, std::max(f[i][x].second, f[i][y].second));
			x = f[i][x].first;
			y = f[i][y].first;
		}
	}
	ans = std::max(ans, std::max(f[0][x].second, f[0][y].second));
	return ans;
}

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		std::cin >> x >> y;
		if (find(x) == find(y)) continue;
		g[x].emplace_back(y, i);
		g[y].emplace_back(x, i);
		fa[find(y)] = find(x);
	}
	dfs(1, 0);
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[i][j].first = f[i - 1][f[i - 1][j].first].first;
			if (f[i][j].first)
				f[i][j].second = std::max(f[i - 1][j].second, f[i - 1][f[i - 1][j].first].second);
		}
	}
	for (int i = 1; i < n; ++i) {
		st[0][i] = qry(i, i + 1);
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 1, k = 1 + (1 << (i - 1)); j + (1 << i) <= n; ++j, ++k) {
			st[i][j] = std::max(st[i - 1][j], st[i - 1][k]);
		}
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		if (x == y) {
			std::cout << "0 ";
			continue;
		}
		--y;
		int d = std::__lg(y - x + 1);
		std::cout << std::max(st[d][x], st[d][y - (1 << d) + 1]) << ' ';
	}
	std::cout << '\n';
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
		dep[i] = 0;
		for (int j = 0; j < 20; ++j) {
			f[j][i] = {0, 0};
			st[j][i] = 0;
		}
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
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}