#include <stdio.h>
#include <algorithm>
#include <cstring>
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int p = 4;
ll dp[1000010][p+1][p+1]; int c[1000010];
int main(){
	memset(dp, -0x3f, sizeof(dp));
	int n, m; scanf("%d%d", &n, &m);
	rep(i, 1, n){
		int a; scanf("%d", &a);
		c[a]++;
	}
	dp[0][0][0] = 0;
	rep(i, 1, m)
		rep(x1, 0, p) rep(x2, 0, p){
			rep(y1, x2, p) rep(y2, 0, p){
				int t = min(c[i] - x1, min(y1 - x2, y2));
				if(t < 0) break;
				dp[i][x1][x2] = max(dp[i][x1][x2], dp[i-1][y1][y2] + t + (c[i] - x1 - t) / 3);
			}
//			printf("dp[%d][%d][%d]:%I64d\n", i, x1, x2, dp[i][x1][x2]);
		}
	ll ans = 0;
	rep(i, 0, p) rep(j, 0, p) ans = max(ans, dp[m][i][j]);
	printf("%I64d\n", ans);
	return 0;
}