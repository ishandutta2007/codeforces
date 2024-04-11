//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, k, x, a[N], pre[N], suf[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x*=x) if(y & 1) ans *= x;
	return ans;
}

int main() {
	scanf("%lld%lld%lld", &n, &k, &x);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) pre[i] = pre[i-1] | a[i];
	per(i, n, 1) suf[i] = suf[i+1] | a[i];
	ll ans = 0;
	rep(i, 1, n) {
		ll now = pre[i-1] | suf[i+1];
		now |= a[i] * qpow(x, k);
		chkmax(ans, now);
	}
	printf("%lld\n", ans);
	return 0;
}