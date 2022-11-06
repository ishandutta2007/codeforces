//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 705, mod = 1e9+7;

ll n, dp[N][N][3][3], ok[N][N];
char s[N];

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	rep(i, 1, n-1) if(s[i] == '(' && s[i+1] == ')') dp[i][i+1][0][1] = dp[i][i+1][0][2] = dp[i][i+1][1][0] = dp[i][i+1][2][0] = ok[i][i+1] = 1;
	rep(delta, 3, n-1) {
		if(!(delta & 1)) continue;
		rep(L, 1, n) {
			ll R = L + delta;
			if(R > n) break;
			if(s[L] != '(' || s[R] != ')') continue;
			if(ok[L+1][R-1]) {
				ll sum = 0;
				rep(i, 0, 2) rep(j, 0, 2) sum = (sum + dp[L+1][R-1][i][j]) % mod;
				dp[L][R][0][1] = (sum - dp[L+1][R-1][0][1] - dp[L+1][R-1][1][1] - dp[L+1][R-1][2][1] + 3 * mod) % mod;
				dp[L][R][0][2] = (sum - dp[L+1][R-1][0][2] - dp[L+1][R-1][1][2] - dp[L+1][R-1][2][2] + 3 * mod) % mod;
				dp[L][R][1][0] = (sum - dp[L+1][R-1][1][0] - dp[L+1][R-1][1][1] - dp[L+1][R-1][1][2] + 3 * mod) % mod;
				dp[L][R][2][0] = (sum - dp[L+1][R-1][2][0] - dp[L+1][R-1][2][1] - dp[L+1][R-1][2][2] + 3 * mod) % mod;
				ok[L][R] = 1;
			}
			else {
				rep(M, L, R-1) {
					if(!ok[L][M] || !ok[M+1][R]) continue;
					dp[L][R][0][0] = (dp[L][R][0][0] + (dp[L][M][0][0] + dp[L][M][0][1] + dp[L][M][0][2]) * (dp[M+1][R][0][0] + dp[M+1][R][1][0] + dp[M+1][R][2][0]) % mod - dp[L][M][0][1] * dp[M+1][R][1][0] % mod - dp[L][M][0][2] * dp[M+1][R][2][0] % mod + 3 * mod) % mod;
					dp[L][R][0][1] = (dp[L][R][0][1] + (dp[L][M][0][0] + dp[L][M][0][1] + dp[L][M][0][2]) * (dp[M+1][R][0][1] + dp[M+1][R][1][1] + dp[M+1][R][2][1]) % mod - dp[L][M][0][1] * dp[M+1][R][1][1] % mod - dp[L][M][0][2] * dp[M+1][R][2][1] % mod + 3 * mod) % mod;
					dp[L][R][0][2] = (dp[L][R][0][2] + (dp[L][M][0][0] + dp[L][M][0][1] + dp[L][M][0][2]) * (dp[M+1][R][0][2] + dp[M+1][R][1][2] + dp[M+1][R][2][2]) % mod - dp[L][M][0][1] * dp[M+1][R][1][2] % mod - dp[L][M][0][2] * dp[M+1][R][2][2] % mod + 3 * mod) % mod;
					dp[L][R][1][0] = (dp[L][R][1][0] + (dp[L][M][1][0] + dp[L][M][1][1] + dp[L][M][1][2]) * (dp[M+1][R][0][0] + dp[M+1][R][1][0] + dp[M+1][R][2][0]) % mod - dp[L][M][1][1] * dp[M+1][R][1][0] % mod - dp[L][M][1][2] * dp[M+1][R][2][0] % mod + 3 * mod) % mod;
					dp[L][R][1][1] = (dp[L][R][1][1] + (dp[L][M][1][0] + dp[L][M][1][1] + dp[L][M][1][2]) * (dp[M+1][R][0][1] + dp[M+1][R][1][1] + dp[M+1][R][2][1]) % mod - dp[L][M][1][1] * dp[M+1][R][1][1] % mod - dp[L][M][1][2] * dp[M+1][R][2][1] % mod + 3 * mod) % mod;
					dp[L][R][1][2] = (dp[L][R][1][2] + (dp[L][M][1][0] + dp[L][M][1][1] + dp[L][M][1][2]) * (dp[M+1][R][0][2] + dp[M+1][R][1][2] + dp[M+1][R][2][2]) % mod - dp[L][M][1][1] * dp[M+1][R][1][2] % mod - dp[L][M][1][2] * dp[M+1][R][2][2] % mod + 3 * mod) % mod;
					dp[L][R][2][0] = (dp[L][R][2][0] + (dp[L][M][2][0] + dp[L][M][2][1] + dp[L][M][2][2]) * (dp[M+1][R][0][0] + dp[M+1][R][1][0] + dp[M+1][R][2][0]) % mod - dp[L][M][2][1] * dp[M+1][R][1][0] % mod - dp[L][M][2][2] * dp[M+1][R][2][0] % mod + 3 * mod) % mod;
					dp[L][R][2][1] = (dp[L][R][2][1] + (dp[L][M][2][0] + dp[L][M][2][1] + dp[L][M][2][2]) * (dp[M+1][R][0][1] + dp[M+1][R][1][1] + dp[M+1][R][2][1]) % mod - dp[L][M][2][1] * dp[M+1][R][1][1] % mod - dp[L][M][2][2] * dp[M+1][R][2][1] % mod + 3 * mod) % mod;
					dp[L][R][2][2] = (dp[L][R][2][2] + (dp[L][M][2][0] + dp[L][M][2][1] + dp[L][M][2][2]) * (dp[M+1][R][0][2] + dp[M+1][R][1][2] + dp[M+1][R][2][2]) % mod - dp[L][M][2][1] * dp[M+1][R][1][2] % mod - dp[L][M][2][2] * dp[M+1][R][2][2] % mod + 3 * mod) % mod;
					ok[L][R] = 1;
					break;
				}
			}
//			rep(i, 0, 2) rep(j, 0, 2) printf("[%lld, %lld] color=[%lld, %lld] ans=%lld\n", L, R, i, j, dp[L][R][i][j]);
		}
	}
	printf("%lld\n", (dp[1][n][0][0]+dp[1][n][0][1]+dp[1][n][0][2]+dp[1][n][1][0]+dp[1][n][1][1]+dp[1][n][1][2]+dp[1][n][2][0]+dp[1][n][2][1]+dp[1][n][2][2])%mod);
    return 0;
}