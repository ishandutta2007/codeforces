#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> p(n);
	std::vector<std::vector<int>> g(n + 1, std::vector<int>());
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i].first >> p[i].second;
		g[p[i].first].push_back(i);
		g[p[i].second].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() > 2) {
			std::cout << "NO\n";
			return;
		}
	}
	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		int c = 0, x = i, y = g[i][0];
		do {
			v[x] = 1;
			if (y == g[x][0]) y = g[x][1];
			else y = g[x][0];
			if (x == p[y].first) x = p[y].second;
			else x = p[y].first;
			++c;
		} while (x != i);
		if (c & 1) {
			std::cout << "NO\n";
			return;
		}
	}
	std::cout << "YES\n";
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