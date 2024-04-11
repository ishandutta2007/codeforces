//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 30;

ll T, n, a[N], b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) scanf("%lld", &b[i]);
		ll ans = 0;
		rep(i, 2, n) ans += min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]), abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
		printf("%lld\n", ans);
	}
	return 0;
}