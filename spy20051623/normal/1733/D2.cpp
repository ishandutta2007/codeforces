#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;
	std::string s, t;
	std::cin >> s >> t;
	std::vector<int> a;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) a.push_back(i);
	}
	int m = a.size();
	if (m & 1) {
		std::cout << "-1\n";
		return;
	}
	if (x >= y) {
		if (m == 2 && a[0] + 1 == a[1]) std::cout << std::min(x, y + y) << '\n';
		else std::cout << m / 2 * y << '\n';
	} else {
		a.insert(a.begin(), 0);
		std::vector<i64> sum(m + 1);
		for (int i = 3; i < m; i += 2) {
			sum[i] = (a[i] - a[i - 1]) * x;
		}
		for (int i = 1; i <= m; ++i) {
			sum[i] += sum[i - 1];
		}
		std::vector<i64> dp(m + 1);
		for (int i = 2; i <= m; i += 2) {
			dp[i] = dp[i - 2] + std::min((a[i] - a[i - 1]) * x, y);
			for (int j = 0; j < i - 2; j += 2) {
				dp[i] = std::min(dp[i], dp[j] + sum[i - 1] - sum[j + 1] + y);
			}
		}
		std::cout << dp[m] << '\n';
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