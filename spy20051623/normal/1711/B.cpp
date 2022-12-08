#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n + 1), c(n + 1);
	std::vector<std::vector<int>> g(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		++c[x], ++c[y];
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans = 0;
	if (m & 1) {
		ans = 2e9;
		for (int i = 1; i <= n; ++i) {
			if (c[i] & 1) ans = std::min(ans, a[i]);
			else {
				for (int j: g[i]) {
					if (c[j] & 1 ^ 1) ans = std::min(ans, a[i] + a[j]);
				}
			}
		}
	}
	std::cout << ans << '\n';
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