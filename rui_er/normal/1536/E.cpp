//LG@rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const ll N = 2e3+5, mod = 1e9+7;

ll T, n, m;
char mp[N][N];
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) ans = ans * x % mod;
	return ans;
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) scanf("%s", mp[i]+1);
		ll qwq = 0;
		rep(i, 1, n) rep(j, 1, m) if(mp[i][j] == '#') ++qwq;
		printf("%lld\n", (qpow(2, qwq)-(qwq==n*m)+mod)%mod);
	}
	return 0;
}