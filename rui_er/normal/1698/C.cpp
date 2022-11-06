// Problem: C. 3SUM Closure
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll posi = 0, nega = 0;
		rep(i, 1, n) {
			if(a[i] > 0) ++posi;
			if(a[i] < 0) ++nega;
		}
		if(posi >= 3 || nega >= 3) puts("NO");
		else {
			vector<ll> v;
			rep(i, 1, n) if(a[i]) v.push_back(a[i]);
			if(v.size() < n) v.push_back(0LL);
			ll sz = v.size(), ok = 1;
			rep(i, 0, sz-1) {
				rep(j, i+1, sz-1) {
					rep(k, j+1, sz-1) {
						ll qwq = 0;
						rep(l, 0, sz-1) qwq |= v[l] == v[i] + v[j] + v[k];
						ok &= qwq;
					}
				}
			}
			puts(ok?"YES":"NO");
		}
	}
	return 0;
}