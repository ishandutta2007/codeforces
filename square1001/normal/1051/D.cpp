#include <iostream>
using namespace std;
const int mod = 998244353;
int n, m; unsigned dp[1009][2009][2];
int main() {
	cin >> n >> m;
	dp[1][1][0] = 2;
	dp[1][2][1] = 2;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j - 1][0] + 2u * dp[i - 1][j][1];
			dp[i][j][0] %= mod;
			dp[i][j][1] = 2u * dp[i - 1][j - 1][0] + dp[i - 1][j][1] + (j >= 2 ? dp[i - 1][j - 2][1] : 0);
			dp[i][j][1] %= mod;
		}
	}
	cout << (dp[n][m][0] + dp[n][m][1]) % mod << '\n';
	return 0;
}