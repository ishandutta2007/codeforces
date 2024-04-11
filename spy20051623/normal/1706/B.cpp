#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::vector<int>> g(n + 1, std::vector<int>());
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		g[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		int f = -1, c = 0;
		for (int j: g[i]) {
			if ((j & 1) != f) {
				++c;
				f = j & 1;
			}
		}
		std::cout << c << ' ';
	}
	std::cout << '\n';
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