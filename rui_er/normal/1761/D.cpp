// LUOGU_RID: 95056121
// Problem: Carry Bit
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1761/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1e6+5, mod = 1e9+7;

ll n, k, pw3[N], fac[N], ifac[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll C(ll x, ll y) {
	if(x < 0 || y < 0 || x < y) return 0;
	return fac[x] * ifac[y] % mod * ifac[x-y] % mod;
}

int main() {
	scanf("%lld%lld", &n, &k);
	pw3[0] = 1;
	rep(i, 1, n) pw3[i] = 3 * pw3[i-1] % mod;
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, n) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = (mod - mod / i) * ifac[mod%i] % mod;
	}
	rep(i, 1, n) ifac[i] = ifac[i-1] * ifac[i] % mod;
	if(!k) return printf("%lld\n", pw3[n])&0;
	rep(i, 1, n) {
		if(i & 1) ans += pw3[n-i] * C(k-1, (i+1)/2-1) % mod * C(n-k, (i+1)/2-1) % mod;
		else ans += pw3[n-i] * C(k-1, i/2-1) % mod * C(n-k, i/2) % mod;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}