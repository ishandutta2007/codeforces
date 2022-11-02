#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
int n, m, lim, delta, dp[2009][2009]; string s;
int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		if (s[i] == '(') delta++;
		else delta--;
		lim = max(lim, -delta);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n - m; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j + 1];
			if (j >= 1) {
				dp[i][j] += dp[i - 1][j - 1];
				if (dp[i][j] >= mod) dp[i][j] -= mod;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= n - m; i++) {
		for (int j = lim; j <= i; j++) {
			int u = j + delta;
			if (u <= n - m) ret = (ret + 1LL * dp[i][j] * dp[n - m - i][u]) % mod;
		}
	}
	cout << ret << endl;
	return 0;
}