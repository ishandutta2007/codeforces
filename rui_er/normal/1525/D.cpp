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
const ll N = 5e3+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N], pos[N], cnt, dp[N][N];

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		if(a[i]) pos[++cnt] = i;
	}
	rep(i, 1, cnt) rep(j, 0, n) dp[i][j] = inf;
	rep(i, 1, cnt) rep(j, 1, n) {
		if(!a[j]) dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+abs(j-pos[i]));
		else dp[i][j] = dp[i][j-1];
	}
	printf("%lld\n", dp[cnt][n]);
	return 0;
}