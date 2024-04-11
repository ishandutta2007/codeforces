#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 5E3 + 10, SIGMA = 26;
const int MOD = 1E9 + 7;

int n;
char s[MAXN];
ll dp[2][MAXN];
ll tot, cnt[SIGMA];

ll inv[MAXN];
ll fac[MAXN], facinv[MAXN];

void getInv(int n = MAXN - 1, ll m = MOD){
	inv[0] = 0, inv[1] = 1;
	fac[0] = fac[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i <= n; ++i){
		inv[i] = inv[m % i] * (m - m / i) % m;
		fac[i] = fac[i - 1] * i % m;
		facinv[i] = facinv[i - 1] * inv[i] % m;
	}
}

ll C(int n, int m){
	return n < m || m < 0 ? 0 : fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}

int main(){
	getInv();

	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
		s[i] -= 'a';
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		ll (&f)[MAXN] = dp[i - 1 & 1], (&g)[MAXN] = dp[i & 1];
		tot = i == 1;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 1; j <= n; ++j){
			g[j] = (tot + MOD - cnt[s[j]]) % MOD;
			tot = (tot + f[j] + MOD - cnt[s[j]]) % MOD;
			cnt[s[j]] = f[j];
		}
		ans = (ans + tot * C(n - 1, i - 2)) % MOD;
	}
	ans = (ans + dp[n & 1][n]) % MOD;
	printf("%d\n", ans);
	return 0;
}