#include <bits/stdc++.h>

using i64 = long long;

i64 p1, p2, t1, t2, h, s;

i64 dmg(i64 x1, i64 x2) {
	return p1 * x1 + p2 * x2 - (x1 + x2 - 1) * s;
}

void solve() {
	std::cin >> p1 >> t1;
	std::cin >> p2 >> t2;
	std::cin >> h >> s;
	std::vector<i64> dp(h + 1, 1e18);
	dp[0] = 0;
	i64 ans = 1e18;
	for (i64 i = 0; i < h; ++i) {
		for (i64 j = 1; j <= 5000; ++j) {
//			i64 kk = (j - 1) * t1 / t2;
//			if (i + j * (p1 - s) + kk * (p2 - s) >= h) ans = std::min(ans, dp[i] + j * t1);
			i64 k = j * t1 / t2;
			if (!k) {
				if (i + j * (p1 - s) >= h) ans = std::min(ans, dp[i] + j * t1);
				continue;
			}
			i64 d = dmg(j, k);
			if (d + i <= h) dp[d + i] = std::min(dp[d + i], dp[i] + j * t1);
			else {
				ans = std::min(ans, dp[i] + j * t1);
				break;
			}
		}
		for (i64 j = 1; j <= 5000; ++j) {
//			i64 kk = (j - 1) * t2 / t1;
//			if (i + kk * (p1 - s) + j * (p2 - s) >= h) ans = std::min(ans, dp[i] + j * t2);
			i64 k = j * t2 / t1;
			if (!k) {
				if (i + j * (p2 - s) >= h) ans = std::min(ans, dp[i] + j * t2);
				continue;
			}
			i64 d = dmg(k, j);
			if (d + i <= h) dp[d + i] = std::min(dp[d + i], dp[i] + j * t2);
			else {
				ans = std::min(ans, dp[i] + j * t2);
				break;
			}
		}
	}
	ans = std::min(ans, dp[h]);
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
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}