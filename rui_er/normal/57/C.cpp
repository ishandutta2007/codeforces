//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, mod = 1e9+7;

ll n, fac[N], ifac[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll C(ll x, ll y) {
	if(x < 0 || y < 0 || x < y) return 0;
	return fac[x] * ifac[y] % mod * ifac[x-y] % mod;
}

int main() {
	scanf("%lld", &n);
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, 2*n) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = (mod - mod / i) * ifac[mod%i] % mod;
	}
	rep(i, 1, 2*n) ifac[i] = ifac[i-1] * ifac[i] % mod;
	printf("%lld\n", (C(2*n, n) + mod - n) % mod);
	return 0;
}