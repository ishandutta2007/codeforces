#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 t, x, y;
	std::cin >> t >> x >> y;
	if (x + y > t) {
		std::cout << "NO\n";
		return;
	}
	std::vector<std::vector<i64>> dp(120, std::vector<i64>(120));
	dp[0][0] = t - x - y;
	for (int i = 0; i < 120; ++i) {
		for (int j = 0; j < 120; ++j) {
			if (j + 1 < 120) dp[i][j + 1] += (dp[i][j] + 1) / 2;
			if (i + 1 < 120) dp[i + 1][j] += dp[i][j] / 2;
		}
	}
	int xx = 0, yy = 0;
	for (int i = 0; i < x + y; ++i) {
		if (xx >= 120 || yy >= 120) break;
		if (dp[xx][yy] & 1) ++xx;
		else ++yy;
	}
	if (xx == x && yy == y) std::cout << "YES\n";
	else std::cout << "NO\n";
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