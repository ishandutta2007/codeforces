//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 5e3+5;

ll n, a[N], dp[N][4], path[N][4], d[3];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	memset(dp, ~0x3f, sizeof(dp));
	rep(j, 0, 3) dp[0][j] = 0;
	rep(i, 1, n+1) {
		rep(j, 0, 3) {
			rep(k, 0, j) {
				ll now = dp[i-1][k] + ((j & 1) ? -a[i] : a[i]);
				if(now > dp[i][j]) {
					dp[i][j] = now;
					path[i][j] = k;
				}
			}
		}
	}
//	rep(i, 1, n+1) rep(j, 0, 3) debug("%lld %lld : %lld %lld\n", i, j, dp[i][j], path[i][j]);
	ll now = 3;
	per(i, n+1, 1) {
		if(path[i][now] < now) {
			rep(j, path[i][now], now-1) d[j] = i - 1;
			now = path[i][now];
		}
	}
	rep(i, 0, 2) printf("%lld%c", d[i], " \n"[i==2]);
	return 0;
}