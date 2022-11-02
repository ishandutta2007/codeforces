#include <cstdio>
#pragma warning(disable : 4996)
const int mod = 1000000007;
int n, a[200009], fact[100009], inv[100009], factinv[100009], dp[4][200009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int b = (n - 1) / 4;
	fact[0] = 1;
	for (int i = 1; i <= 2 * b; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[1] = 1;
	for (int i = 2; i <= 2 * b; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv[0] = 1;
	for (int i = 1; i <= 2 * b; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
	for (int i = 0; i <= 2 * b; i++) dp[0][2 * i] = dp[1][2 * i] = dp[1][2 * i + 1] = 1LL * fact[2 * b] * factinv[i] % mod * factinv[2 * b - i] % mod;
	for (int i = 0; i <= 2 * b + 1; i++) {
		dp[2][2 * i] = dp[1][2 * i] - (i != 0 ? dp[1][2 * i - 1] : 0); if (dp[2][2 * i] < 0) dp[2][2 * i] += mod;
		dp[2][2 * i + 1] = dp[1][2 * i] + dp[1][2 * i + 1]; if (dp[2][2 * i + 1] >= mod) dp[2][2 * i + 1] -= mod;
	}
	for (int i = 0; i <= 2 * b + 1; i++) {
		dp[3][2 * i] = dp[2][2 * i] + (i != 0 ? dp[2][2 * i - 1] : 0); if (dp[3][2 * i] >= mod) dp[3][2 * i] -= mod;
		dp[3][2 * i + 1] = dp[2][2 * i] - dp[2][2 * i + 1]; if (dp[3][2 * i + 1] < 0) dp[3][2 * i + 1] += mod;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) ret = (ret + 1LL * a[i] * dp[(n - 1) % 4][i]) % mod;
	printf("%d\n", ret);
	return 0;
}