#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int dp[410][210][210], ans[210];
long long f[410], dw[410], fac[410], inv[410];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

int main() {
	for (int i = 2; i <= 405; i++) f[i] = power(i, mod - 2);
	fac[0] = inv[0] = 1; for (int i = 1; i <= 405; i++) fac[i] = fac[i - 1] * i % mod, inv[i] = power(fac[i], mod - 2);
	int n, k; cin >> n >> k;
	dw[0] = 1; for (int i = 1; i <= 405; i++) dw[i] = dw[i - 1] * (n - i + 1) % mod;
	dp[0][0][2] = 1;
	for (int i = 0; i <= 2 * k; i++) {
		for (int j = 0; j <= k; j++) {
			for (int t = 2; t <= k + 1; t++) {
				if (!dp[i][j][t]) continue;
				add(dp[i][j][t + 1], dp[i][j][t]);
				long long tmp = dp[i][j][t];
				for (int s = 1; j + s * (t - 1) <= k; s++) {
					tmp = tmp * f[t] % mod;
					add(dp[i + s * t][j + s * (t - 1)][t + 1], tmp * inv[s] % mod);
				}
			}
			int val = i <= n ? dp[i][j][k + 2] * dw[i] % mod : 0;
			for (int t = j; t <= k; t += 2) add(ans[t], val);
		}
	}
	for (int i = 1; i <= k; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}