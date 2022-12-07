// LUOGU_RID: 95054468
// Problem: C. Complex Market Analysis
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/C
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
const ll N = 1e6+5;

ll T, n, e, a[N], pre[N], suf[N], tab[N], p[N], pcnt;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void sieve(ll lim) {
	tab[1] = 1;
	rep(i, 2, lim) {
		if(!tab[i]) p[++pcnt] = i;
		for(ll j = 1; j <= pcnt && i * p[j] <= lim; j++) {
			tab[i*p[j]] = 1;
			if(!(i % p[j])) break;
		}
	}
}

int main() {
	sieve(N-5);
	for(scanf("%lld", &T); T; T--) {
		scanf("%lld%lld", &n, &e);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, e) pre[i] = a[i] == 1;
		rep(i, e+1, n) pre[i] = a[i] == 1 ? pre[i-e] + 1 : 0;
		per(i, n, n-e+1) suf[i] = a[i] == 1;
		per(i, n-e, 1) suf[i] = a[i] == 1 ? suf[i+e] + 1 : 0;
		ll ans = 0;
		rep(i, 1, n) {
			if(!tab[a[i]]) {
				ll L = i - e >= 1 ? pre[i-e] : 0;
				ll R = i + e <= n ? suf[i+e] : 0;
				ans += (L + 1) * (R + 1) - 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}