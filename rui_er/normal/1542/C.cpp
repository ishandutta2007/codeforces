//LG rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 55, mod = 1e9+7;

ll T, n, qwq[N] = {1, 1}, now[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	rep(i, 2, 40) qwq[i] = i / __gcd(i, qwq[i-1]) * qwq[i-1];// % mod;
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, 40) {
			now[i] = n / qwq[i];
//			printf("%lld%c", now[i], " \n"[i==40]);
		}
		ll ans = 0, tmp = 0;
		per(i, 40, 1) {
			now[i] = (now[i] - tmp + mod) % mod;
			tmp = (tmp + now[i] + mod) % mod;
			ans = (ans + now[i] % mod * (i + 1) % mod) % mod;
//			printf("%lld %lld %lld\n", now[i], tmp, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}