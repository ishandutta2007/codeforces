#include <iostream>
using namespace std;
const int mod = 1000000007;
int a, b, n, t, dp[209][410009];
int main() {
	cin >> a >> b >> n >> t; t *= 2;
	dp[0][n * (t + 1)] = 1;
	for (int i = 1; i <= t; i++) {
		int sum = 0;
		for (int j = n * (t - i); j <= n * (t - i + 2); j++) {
			sum += dp[i - 1][j];
			if (sum >= mod) sum -= mod;
		}
		for (int j = n * (t - i + 1); j <= n * (t + i + 1); j++) {
			dp[i][j] = sum;
			sum -= dp[i - 1][j - n]; if (sum < 0) sum += mod;
			sum += dp[i - 1][j + n + 1]; if (sum >= mod) sum -= mod;
		}
	}
	int ret = 0;
	for (int i = n * (t + 1) + b - a + 1; i <= n * (2 * t + 1); i++) {
		ret += dp[t][i];
		if (ret >= mod) ret -= mod;
	}
	cout << ret << endl;
	return 0;
}