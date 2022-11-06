//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll n, ans;
ll qpow(ll a, ll b) {
	ll res = 1;
	for(;b;b>>=1,a=a*a%mod) if(b & 1) res = res * a % mod;
	return res;
}

int main() {
	scanf("%lld", &n);
	ans = (qpow(27, n) - qpow(7, n) + mod) % mod;
	printf("%lld\n", ans);
	return 0;
}