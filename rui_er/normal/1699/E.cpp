// Problem: E. Three Days Grace
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
const ll N = 5e6+5;

ll T, n, m, a[N], buc[N], now[N], id[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, m) buc[i] = now[i] = 0, id[i] = i;
		rep(i, 1, n) buc[a[i]] = now[a[i]] = 1;
		ll mn = *min_element(a+1, a+1+n), mx = *max_element(a+1, a+1+n);
		ll ans = mx - mn, R = mx;
		per(L, mx, 1) {
			for(ll i=L*L;i<=mx;i+=L) {
				if(buc[i]) --now[id[i]];
				chkmin(id[i], id[i/L]);
				if(buc[i]) ++now[id[i]];
			}
			while(!now[R]) --R;
			if(L <= mn) chkmin(ans, R-L);
		}
		printf("%lld\n", ans);
	}
	return 0;
}