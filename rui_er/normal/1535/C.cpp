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
const ll N = 2e5+5;

ll n, dp[N][2], len[N];
char s[N];

int main() {
	mulT0 {
		scanf("%s", s+1);
		n = strlen(s+1);
		rep(i, 1, n) dp[i][0] = dp[i][1] = len[i] = 0;
		rep(i, 1, n) if(s[i] == '?') len[i] = len[i-1] + 1;
		rep(i, 1, n) {
			if(s[i] == '0') dp[i][0] = dp[i-1][1] + 1;
			else if(s[i] == '1') dp[i][1] = dp[i-1][0] + 1;
			else {
				dp[i][0] = dp[i-1][1] + 1;
				dp[i][1] = dp[i-1][0] + 1;
			}
//			fprintf(stderr, "DP[%lld][0] = %lld; DP[%lld][1] = %lld\n", i, dp[i][0], i, dp[i][1]);
		}
		ll ans = 0;
		rep(i, 1, n) ans += dp[i][0] + dp[i][1] - len[i];
		printf("%lld\n", ans);
	}
	return 0;
}