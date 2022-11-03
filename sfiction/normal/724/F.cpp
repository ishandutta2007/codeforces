#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E3 + 10, MAXD = 10 + 2;
int MOD;

ll inv[20];
ll dp[2][MAXN][MAXD];

ll Com(ll n, ll m){
	n %= MOD;
	if (m < 0 || n < m)
		return 0;
	ll ret = n;
	for (int i = 1; i < m; ++i)
		ret = ret * (n - i) % MOD * inv[i + 1] % MOD;
	return ret;
}

int main(){
	int n, d;
	scanf("%d%d%d", &n, &d, &MOD);
	if (n <= 2){
		puts("1");
		return 0;
	}
	inv[0] = 0, inv[1] = 1;
	for (int i = 2; i <= d; ++i)
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	int n0 = n - 1 >> 1;
	for (int i = 0; i <= d; ++i)
		dp[1][i + 1][i] = 1;
	for (int k = 2; k <= n0; ++k){
		ll (&f)[MAXN][MAXD] = dp[k - 1 & 1], (&g)[MAXN][MAXD] = dp[k & 1];

		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= d; ++j){
				g[i][j] = f[i][j];
				for (int t = 1; t <= j && k * t < i; ++t)
					g[i][j] = (g[i][j] + f[i - k * t][j - t] * Com(f[k][d - 1] + t - 1, t) % MOD) % MOD;
			}
	}
	ll ans = dp[n0 & 1][n][d];
	if (n + 1 & 1)
		ans = (ans + Com(dp[n0 & 1][n >> 1][d - 1] + 1, 2)) % MOD;
	printf("%d\n", (int)ans);
	return 0;
}