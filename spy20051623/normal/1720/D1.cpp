#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n), dp(n, 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = std::max(0, i - 512); j < i; ++j) {
			if ((a[j] ^ i) < (a[i] ^ j)) dp[i] = std::max(dp[i], dp[j] + 1);
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
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