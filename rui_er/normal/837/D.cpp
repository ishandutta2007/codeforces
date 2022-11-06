//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 205, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, k, a[N], dp[N][N*26], ans;
/* >>> from math import log
 * >>> log(1e18)/log(5)
 * 25.752178045321074
**/
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
ll calc(ll x, ll p) {
	ll ans = 0;
	while(x && !(x % p)) x /= p, ++ans;
	return ans;
}

int main() {
	memset(dp, ~0x3f, sizeof(dp));
	dp[0][0] = 0;
	scanf("%lld%lld", &n, &k);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		ll lim = min(k, i);
		per(j, lim, 1) {
			ll five = calc(a[i], 5);
			ll two = calc(a[i], 2);
			per(fac, N*26-1, five) {
				chkmax(dp[j][fac], dp[j-1][fac-five]+two);
			}
		}
	}
	rep(i, 0, N*26-1) {
		chkmax(ans, min(i, dp[k][i]));
	}
	printf("%lld\n", ans);
	return 0;
}