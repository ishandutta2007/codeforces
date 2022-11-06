//LG rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 505, mod = 998244353ll;

ll n, op[N], a[N], b[N], tot, c[N], dp[N][N], ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void DP(int x, int y, int k, int t) {
	rep(i, x, y) {
		rep(j, 0, n) dp[i][j] = dp[i-1][j];
		if(!op[i]) {
			bool qwq = t ? (a[i] <= k) : (a[i] < k);
			if(qwq) rep(j, 1, n) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
			else rep(j, 0, n) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
		}
		else {
			rep(j, 0, n) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
			if(t) dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
		}
	}
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		char s[2];
		scanf("%s", s);
		if(s[0] == '+') {
			op[i] = 0;
			scanf("%lld", &a[i]);
//			c[++tot] = b[i] = a[i];
		}
		else op[i] = 1;
	}
//	sort(c+1, c+1+tot);
//	tot = unique(c+1, c+1+tot) - c;
//	rep(i, 1, n) b[i] = lower_bound(c+1, c+1+tot, b[i]) - c;
	rep(i, 1, n) {
		if(op[i]) continue;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		DP(1, i-1, a[i], 1);
		rep(j, 0, n) dp[i][j] = dp[i-1][j];
		DP(i+1, n, a[i], 0);
		ll mul = 0;
		rep(j, 0, n) mul = (mul + dp[n][j]) % mod;
		ans = (ans + mul * a[i] % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}