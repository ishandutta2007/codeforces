// LUOGU_RID: 93139893
// Problem: D. Count GCD
// Contest: Codeforces - CodeTON Round 3 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1750/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const ll N = 2e5+5, mod = 998244353;

ll T, n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll calc(ll pre, ll now) {
	if(pre == now) return m / now;
	pre /= now;
	ll lim = m / now;
	vector<ll> d;
	for(ll i = 2; i * i <= pre; i++) {
		if(!(pre % i)) {
			d.push_back(i);
			while(!(pre % i)) pre /= i;
		}
	}
	if(pre > 1) d.push_back(pre);
	ll n = d.size(), ans = 0;
	rep(S, 0, (1LL << n) - 1) {
		ll now = 1, mul = (__builtin_popcountll(S) & 1) ? mod - 1 : 1;
		rep(i, 0, n - 1) if((S >> i) & 1) now *= d[i];
		now = lim / now;
		ans = (ans + mul * now % mod) % mod;
	}
	return ans;
}

int main() {
	for(scanf("%lld", &T); T; T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll ok = 1;
		rep(i, 2, n) ok &= !(a[i-1] % a[i]);
		if(!ok) {puts("0"); continue;}
		ll ans = 1;
		rep(i, 2, n) ans = ans * calc(a[i-1], a[i]) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}