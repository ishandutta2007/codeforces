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
const ll N = 1e5+5;

ll n, c[N], a[N], b[N], dp[N], ans;

int main() {
	mulT0 {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &c[i]);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) scanf("%lld", &b[i]);
		rep(i, 2, n) {
			if(a[i] == b[i]) dp[i] = c[i] + 1;
			else {
				int qwq = abs(a[i]-b[i]);
				dp[i] = max(dp[i-1]-qwq+1+c[i], qwq+1+c[i]);
			}
			ans = max(ans, dp[i]);
		}
		printf("%lld\n", ans);
		rep(i, 1, n) dp[i] = 0; ans = 0;
	}
	return 0;
}