//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 105;

int n, a[N], remO, remE, dp[N][N][N][2];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	remO = (n + 1) / 2;
	remE = n / 2;
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i]) {
			if(a[i] & 1) --remO;
			else --remE;
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][remO][remE][0] = dp[0][remO][remE][1] = 0;
	rep(i, 1, n) {
		rep(j, 0, remO) {
			rep(k, 0, remE) {
				if(a[i]) {
					if(a[i] & 1) {
						chkmin(dp[i][j][k][0], dp[i-1][j][k][0]);
						chkmin(dp[i][j][k][0], dp[i-1][j][k][1] + 1);
					}
					else {
						chkmin(dp[i][j][k][1], dp[i-1][j][k][0] + 1);
						chkmin(dp[i][j][k][1], dp[i-1][j][k][1]);
					}
				}
				else {
					if(j < remO) {
						chkmin(dp[i][j][k][0], dp[i-1][j+1][k][0]);
						chkmin(dp[i][j][k][0], dp[i-1][j+1][k][1] + 1);
					}
					if(k < remE) {
						chkmin(dp[i][j][k][1], dp[i-1][j][k+1][0] + 1);
						chkmin(dp[i][j][k][1], dp[i-1][j][k+1][1]);
					}
				}
//				debug("DP[%d][%d][%d] = {%d, %d}\n", i, j, k, dp[i][j][k][0], dp[i][j][k][1]);
			}
		}
	}
	printf("%d\n", min(dp[n][0][0][0], dp[n][0][0][1]));
	return 0;
}