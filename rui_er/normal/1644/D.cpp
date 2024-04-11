//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, mod = 998244353;

ll T, n, m, k, q, x[N], y[N], cx[N], cy[N], Cx, Cy;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
		rep(i, 1, q) scanf("%lld%lld", &x[i], &y[i]);
		ll ans = 1;
		per(i, q, 1) {
			if(Cx == n || Cy == m) break;
			ll mul = 1;
			if(!cx[x[i]]) {
				cx[x[i]] = 1;
				++Cx;
				mul = k;
			}
			if(!cy[y[i]]) {
				cy[y[i]] = 1;
				++Cy;
				mul = k;
			}
			ans = ans * mul % mod;
		}
		printf("%lld\n", ans);
		rep(i, 1, q) cx[x[i]] = cy[y[i]] = 0;
		Cx = Cy = 0;
	}
	return 0;
}