#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<std::bitset<100>> b(n);
	std::vector<int> vis(n);
	std::function<void(int)> dfs = [&](int p) {
		if (vis[p]) return;
		vis[p] = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i][p] - '0') {
				dfs(i);
				b[p] |= b[i];
			}
		}
		b[p][p] = true;
	};
	for (int i = 0; i < n; ++i) {
		dfs(i);
	}
	for (int i = 0; i < n; ++i) {
		std::cout << b[i].count();
		for (int j = 0; j < n; ++j) {
			if (b[i][j]) std::cout << ' ' << j + 1;
		}
		std::cout << '\n';
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