//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 405;

ll n, mod, c[N][N], s[N], dp[N][N], ans;

int main() {
	scanf("%lld%lld", &n, &mod);
	rep(i, 0, n) c[i][0] = 1; s[0] = 1;
	rep(i, 1, n) {
		rep(j, 1, i) {
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
			s[i] = (s[i] + c[i][j]) % mod;
		}
		++s[i];
	}
	dp[1][1] = 1;
	rep(i, 2, n) {
		dp[i][i] = (dp[i][i] + s[i-1]) % mod;
		rep(j, 2, i-1) rep(k, 1, i-j) {
			ll delta = dp[j-1][j-1] * dp[i-j][k] % mod * c[j+k-1][j-1] % mod;
			dp[i][j+k-1] = (dp[i][j+k-1] + delta) % mod;
		}
	}
	rep(i, 1, n) ans = (ans + dp[n][i]) % mod;
	printf("%lld\n", ans);
	return 0;
}