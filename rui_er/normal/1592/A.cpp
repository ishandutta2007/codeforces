//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e3+5;

ll T, n, H, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &H);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll mx = 0, nx = 0;
		rep(i, 1, n) {
			if(a[i] > mx) {
				nx = mx;
				mx = a[i];
			}
			else if(a[i] > nx) nx = a[i];
		}
		ll s = mx + nx;
		ll ans = H / s;
		H -= ans * s;
		ans <<= 1;
		if(!H);
		else if(H <= mx) ++ans;
		else ans += 2;
		printf("%lld\n", ans);
	}
	return 0;
}