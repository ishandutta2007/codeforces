#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> g(n + 1, std::vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	std::vector<int> dpt(n + 1), fa(n + 1);
	std::function<void(int)> dfs = [&](int p) {
		for (int i: g[p]) {
			if (i == fa[p]) continue;
			dpt[i] = dpt[p] + 1;
			fa[i] = p;
			dfs(i);
		}
	};
	dfs(1);
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(20));
	for (int i = 1; i <= n; ++i) {
		f[i][0] = fa[i];
	}
	for (int i = 1; i < 20; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dpt[j] >= 1 << i) f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	std::function<bool(int, int)> check = [&](int x, int y) {
		int d = dpt[x] - dpt[y];
		for (int i = 0; i < 20; ++i) {
			if (d >> i & 1) x = f[x][i];
		}
		return x == y;
	};
	int q;
	std::cin >> q;
	while (q--) {
		int k;
		std::cin >> k;
		std::vector<int> a(k), b(k);
		for (int i = 0; i < k; ++i) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end(), [&](int x, int y) {
			return dpt[x] == dpt[y] ? x < y : dpt[x] < dpt[y];
		});
		bool ok = true;
		int l = 1, r = 1;
		for (int i = 0; i < k; ++i) {
			if (check(a[i], l)) l = a[i];
			else if (check(a[i], r)) r = a[i];
			else {
				ok = false;
				break;
			}
		}
		if (ok && r != a[0]) {
			int x = l, y = r;
			if (dpt[x] < dpt[y]) std::swap(x, y);
			int d = dpt[x] - dpt[y];
			for (int i = 0; i < 20; ++i) {
				if (d >> i & 1) x = f[x][i];
			}
			if (x != y) {
				for (int i = 19; i >= 0; --i) {
					if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
				}
				x = y = fa[x];
			}
			if (dpt[a[0]] < dpt[x]) ok = false;
		}
		if (ok) std::cout << "YES\n";
		else std::cout << "NO\n";
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