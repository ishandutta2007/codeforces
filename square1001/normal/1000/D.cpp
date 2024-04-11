#include <iostream>
using namespace std;
const int mod = 998244353;
int n, a[1009], dp[1009], comb[1009][1009];
int calc_comb(int a, int b) {
	return b < 0 || a < b ? 0 : comb[a][b];
}
int main() {
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
			if (comb[i][j] >= mod) comb[i][j] -= mod;
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] >= 1) {
			dp[i] = 1;
			for (int j = 0; j < i; ++j) {
				dp[i] = (dp[i] + 1LL * dp[j] * calc_comb(i - j - 1, a[j])) % mod;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret = (ret + 1LL * dp[i] * calc_comb(n - i - 1, a[i])) % mod;
	}
	cout << ret << '\n';
	return 0;
}