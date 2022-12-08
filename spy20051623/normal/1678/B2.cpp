#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		while (i < n - 1 && s[i + 1] == s[i]) {
			++i;
			++cnt;
		}
		sum += cnt;
		if (sum & 1) ++ans;
	}
	cout << ans << " ";
	vector<vector<int>> dp(n / 2, vector<int>(2));
	if (s[0] == s[1]) {
		dp[0][s[0] - '0'] = 1;
		dp[0][s[0] - '0' ^ 1] = 1e9;
	} else {
		dp[0][0] = dp[0][1] = 1;
	}
	for (int i = 2; i < n; i += 2) {
		if (s[i] == s[i + 1]) {
			dp[i / 2][s[i] - '0'] = min(dp[i / 2 - 1][s[i] - '0'], dp[i / 2 - 1][s[i] - '0' ^ 1] + 1);
			dp[i / 2][s[i] - '0' ^ 1] = 1e9;
		} else {
			dp[i / 2][0] = min(dp[i / 2 - 1][0], dp[i / 2 - 1][1] + 1);
			dp[i / 2][1] = min(dp[i / 2 - 1][1], dp[i / 2 - 1][0] + 1);
		}
	}
	cout << min(dp[n / 2 - 1][0], dp[n / 2 - 1][1]) << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}