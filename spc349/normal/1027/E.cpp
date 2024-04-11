#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int inv2 = 499122177;

int dp[510][510], ndp[510][510];
int f[510];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	int n, k; cin >> n >> k;
	dp[0][0] = 1;
	for (int it = 0; it < n; it++) {
		memset(ndp, 0, sizeof(ndp));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (!dp[i][j]) continue;
				add(ndp[i + 1][max(i + 1, j)], dp[i][j]);
				add(ndp[1][max(1, j)], dp[i][j]);
			}
		}
		swap(dp, ndp);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[j] = (f[j] + dp[i][j]) % mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i * j < k) ans = (ans + 1ll * f[i] * f[j]) % mod;
		}
	}
	ans = ans * inv2 % mod;
	printf("%I64d\n", ans);
	return 0;
}