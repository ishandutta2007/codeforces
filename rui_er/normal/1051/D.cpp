//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e3+5, mod = 998244353ll;

ll n, k, dp[N][N][4];
/*
 * 0 => WW
 * 1 => WB
 * 2 => BW
 * 3 => BB
**/
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &k);
	dp[1][1][0] = dp[1][2][1] = dp[1][2][2] = dp[1][1][3] = 1;
	rep(i, 2, n) {
		rep(j, 1, k) {
			dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3]) % mod;
			dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1] + (j >= 2) * dp[i-1][j-2][2] + dp[i-1][j-1][3]) % mod;
			dp[i][j][2] = (dp[i-1][j-1][0] + (j >= 2) * dp[i-1][j-2][1] + dp[i-1][j][2] + dp[i-1][j-1][3]) % mod;
			dp[i][j][3] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3]) % mod;
		}
	}
	printf("%lld\n", (dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod);
    return 0;
}