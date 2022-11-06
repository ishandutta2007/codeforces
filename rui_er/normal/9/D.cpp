//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 45;

ll n, m, dp[N][N], ans;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 0, n) dp[i][0] = 0, dp[0][i] = 1;
	rep(i, 1, n) rep(j, 1, n) rep(k, 0, j-1) dp[j][i] += dp[k][i-1] * dp[j-k-1][i-1];
	ans = dp[n][n] - dp[n][m-1];
	printf("%lld\n", ans);
	return 0;
}