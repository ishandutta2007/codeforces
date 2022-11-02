#include <stdio.h>
#include <cstring>
typedef long long ll;
const int MOD = 1e9 + 7;
int K, g[62][62], inv[62];
void Work(int t){
	for(int i = 0; i <= t; i++)
		g[t][i] = i == t;
	for(int k = 1; k <= K; k++)
		for(int i = 0; i <= t; i++){
			for(int j = 0; j < i; j++)
				g[t][j] = (g[t][j] + (ll)g[t][i] * inv[i + 1] % MOD) % MOD;
			g[t][i] = (ll)g[t][i] * inv[i + 1] % MOD;
		}
}
int f(ll p, int a){
	p %= MOD;
	int rnt = 0;
	if(g[a][a] == -1) Work(a);
	for(int i = 0, j = 1; i <= a; i++){
		rnt = (rnt + (ll)g[a][i] * j % MOD) % MOD;
		j = (ll)j * p % MOD;
	}
	return rnt;
}
int main(){
	memset(g, -1, sizeof(g));
	for(int i = 1; i < 62; i++)
		inv[i] = i == 1 ? 1 : (ll)inv[MOD%i]*(MOD-MOD/i)%MOD;
	ll n; scanf("%I64d%d", &n, &K);
	ll ans = 1;
	for(ll p = 2; p <= n / p; p++)
		if(n % p == 0){
			int alpha = 0;
			while(n % p == 0) alpha++, n /= p;
			ans = ans * f(p, alpha) % MOD;
		}
	if(n > 1) ans = ans * f(n, 1) % MOD;
	printf("%I64d\n", ans);
	return 0;
}