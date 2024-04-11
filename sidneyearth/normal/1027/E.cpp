#include <stdio.h>
#include <algorithm>
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define per(i, j, k) for(int i = (j); i >= (k); --i)
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int maxn = 510;
int f[maxn][maxn][2], s[maxn][2], c[maxn], g[maxn];
int Inv(int a){ return a == 1 ? 1 : (ll)Inv(MOD%a)*(MOD-MOD/a)%MOD; }
int main(){
	int inv2 = Inv(2);
	int n, K;
	scanf("%d%d", &n, &K);
	s[0][0] = s[0][1] = 1;
	rep(k, 1, n){
		rep(i, 1, n){
			int mn = i < k ? i : k;
			s[i][0] = 0; s[i][1] = 0;
			rep(j, 1, mn) rep(t, 0, 1){
				f[i][j][t] = j == 1 ? s[i-1][t^1] : f[i-1][j-1][t];
				s[i][t] = (s[i][t] + f[i][j][t]) % MOD;
			}
		}
		rep(i, 1, k)
			c[k] = ((c[k] + f[n][i][0]) % MOD + f[n][i][1]) % MOD;
	}
	rep(i, 1, n) rep(j, 1, i - 1)
		c[i] = (c[i] - c[j] + MOD) % MOD;
	per(i, n, 1) g[i] = (c[i] + g[i+1]) % MOD;
	int ans = 0;
	rep(i, 1, n) ans = (ans + (ll)c[i] * g[min(n + 1, (K-1)/i+1)] % MOD) % MOD;
	ans = (ll)ans * inv2 % MOD;
	ans = (MOD - ans) % MOD;
	ans = (ans + (ll)g[1] * g[1] % MOD * inv2 % MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}