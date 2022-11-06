//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e5+5, mod = 998244353;

ll T, n, a[N], pre[N], suf[N], fac[N], ifac[N];
map<ll, ll> cntPre, cntSuf;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void initC(ll lim) {
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, lim) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = (mod - mod / i) * ifac[mod%i] % mod;
	}
	rep(i, 1, lim) ifac[i] = ifac[i-1] * ifac[i] % mod;
}
ll C(ll n, ll m) {
	if(n < 0 || m < 0 || n < m) return 0;
	return fac[n] * ifac[m] % mod * ifac[n-m] % mod;
}
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) ans = ans * x % mod;
	return ans;
}
ll inv(ll x) {return qpow(x, mod-2);}
// .....[.....].....
// <-x->|<-y->|<-x->
// if a[i] > 0; position of | is certain
// if a[i] == 0; combinatorics(?)(upd: !)
// so hard
// omg, i can't think actively after 00:00 UTC+8

int main() {
	initC(N-5);
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) {
			pre[i] = pre[i-1] + a[i];
			++cntPre[pre[i]];
		}
		per(i, n, 1) suf[i] = suf[i+1] + a[i];
		ll now = 1, ans = 1;
		per(i, n, 1) {
			ll x = pre[i], y = suf[i];
			now = now * inv(C(cntPre[x] + cntSuf[x], cntPre[x])) % mod * C(cntPre[x] + cntSuf[x] - 1, cntPre[x] - 1) % mod;
			--cntPre[x];
			now = now * inv(C(cntPre[y] + cntSuf[y], cntSuf[y])) % mod * C(cntPre[y] + cntSuf[y] + 1, cntSuf[y] + 1) % mod;
			++cntSuf[y];
			if(cntPre[y]) ans = (ans + now * inv(C(cntPre[y] + cntSuf[y], cntPre[y])) % mod * C(cntPre[y] + cntSuf[y] - 1, cntPre[y] - 1) % mod) % mod;
		}
		printf("%lld\n", ans);
		cntPre.clear();
		cntSuf.clear();
		rep(i, 1, n) pre[i] = suf[i] = 0;
	}
	return 0;
}