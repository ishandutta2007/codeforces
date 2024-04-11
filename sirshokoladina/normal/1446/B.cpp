#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1] - 1);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j] - 1);
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}