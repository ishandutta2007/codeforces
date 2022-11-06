//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 3e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, a[N], b[N], dp[N][3];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld%lld", &a[i], &b[i]);
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		rep(i, 1, n) rep(j, 0, 2) dp[i][j] = inf;
		rep(i, 1, n) {
			rep(j, 0, 2) {
				rep(k, 0, 2) {
					if(i > 1 && a[i-1] + k == a[i] + j) continue;
					chkmin(dp[i][j], dp[i-1][k] + j * b[i]);
				}
			}
		}
		printf("%lld\n", min({dp[n][0], dp[n][1], dp[n][2]}));
	}
	int _ = 0;
	return (0^_^0);
}