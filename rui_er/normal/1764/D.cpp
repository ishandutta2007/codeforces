// LUOGU_RID: 96019838
// Problem: Doremy's Pegging Game
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1764/problem/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
const ll N = 1e4+5;

ll n, mod, fac[N], ifac[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll C(ll x, ll y) {
	if(x < 0 || y < 0 || x < y) return 0;
	return fac[x] * ifac[y] % mod * ifac[x-y] % mod;
}

int main() {
	scanf("%lld%lld", &n, &mod);
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	rep(i, 2, 2*n) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = (mod - mod / i) * ifac[mod%i] % mod;
	}
	rep(i, 1, 2*n) ifac[i] = ifac[i-1] * ifac[i] % mod;
	// 1 ~ n/2 deleted, n not deleted
	rep(i, n/2+1, n) { // first not deleted
		// last deleted in [i-n/2, n/2]
		// enumerate how many deleted in [i+1, n-1]
		rep(j, 0, max((n-1)-(i+1)+1, 0LL)) {
			ans += C(max((n-1)-(i+1)+1, 0LL), j) * fac[j+i-2] % mod * ((n / 2) - (i - n / 2) + 1) % mod;
			ans %= mod;
		}
	}
	printf("%lld\n", ans*n%mod);
	return 0;
}