#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 2;
typedef long long LL;

pair<int, int> gen(LL x) {
	pair<int, int> ans = make_pair(0,0);
	while (x % 2 == 0) {
		x /= 2; ans.first ++;
	}
	while (x % 5 == 0) {
		x /= 5; ans.second ++;
	}
	return ans;
}
int n, k;
LL a[N];
const int inf = 1e9;
int dp[N][N * 30], pd[N][30 * N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	for (int cnt = 0; cnt < N; cnt ++)
	for (int j = 0; j < 30 * N; j ++)
		dp[cnt][j] = - inf;

	dp[0][0] = 0;
	for (int i = 0; i < n; i ++) {		
		for (int cnt = 0; cnt < N; cnt ++)
		for (int j = 0; j < 30 * N; j ++)
			pd[cnt][j] = -inf;

		pair<int, int> f = gen(a[i+1]);
		for (int cnt = 0; cnt <= i; cnt ++)
		for (int j = 0; j <= 30 * i; j ++) {
			if (dp[cnt][j] < inf) {
				//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
				
				pd[cnt][j] = max(pd[cnt][j], dp[cnt][j]);
				pd[cnt + 1][j + f.second] = max(dp[cnt][j] + f.first, pd[cnt + 1][j + f.second]);
			}
		}
		for (int cnt = 0; cnt < N; cnt ++)
		for (int j = 0; j < 30 * N; j ++)
			dp[cnt][j] = pd[cnt][j];
	}
	int ans = 0;
	for (int i = 0; i <= 30 * n; i ++) {
		ans = max(ans, min(i, dp[k][i]));
	}
	printf("%d\n", ans);
}