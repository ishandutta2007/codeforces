#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < (n + 1) / 2; ++j) {
			int x = a[i][j] + a[j][n - 1 - i] + a[n - 1 - i][n - 1 - j] + a[n - 1 - j][i] - 48 * 4;
			ans += std::min(x, 4 - x);
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