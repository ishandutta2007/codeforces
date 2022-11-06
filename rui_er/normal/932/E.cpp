//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%d", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 5e3+5, mod = 1e9+7;

ll qpow(ll a, ll b) {
	ll res = 1;
	for(;b;b>>=1,a=a*a%mod) if(b & 1) res = res * a % mod;
	return res;
}
 
ll n, k, stirling2[N][N], ans, qwq = 1;
void initStirling2() {stirling2[0][0] = 1; rep(i, 1, k) rep(j, 1, k) stirling2[i][j] = (stirling2[i-1][j-1] + stirling2[i-1][j] * j) % mod;}
 
int main() {
	scanf("%lld%lld", &n, &k);
	initStirling2();
	ll _ = min(n, k);
	rep(i, 0, _) {
		(ans += stirling2[k][i] * qwq % mod * qpow(2, n-i) % mod) %= mod;
		(qwq *= n - i) %= mod;
	}
	printf("%lld\n", ans);
 	return 0;
}