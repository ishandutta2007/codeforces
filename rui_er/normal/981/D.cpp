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
const ll N = 55;

ll n, k, a[N], s[N], dp[N][N], ans;
bool check(ll x) {
	fil(dp, 0); dp[0][0] = 1;
	rep(R, 1, n) rep(L, 0, R-1) rep(i, 1, k) dp[R][i] |= dp[L][i-1] & (((s[R] - s[L]) & x) == x);
	return dp[n][k];
}

int main() {
	scanf("%lld%lld", &n, &k);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) s[i] = s[i-1] + a[i];
	per(i, 63, 0) ans |= check(ans|(1LL<<i)) ? (1LL << i) : 0LL;
	printf("%lld\n", ans);
	return 0;
}