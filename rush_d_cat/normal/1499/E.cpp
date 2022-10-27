#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
const LL MOD = 998244353;

char x[N], y[N];
LL dp[N][N][2];

void add(LL &x, LL y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	scanf("%s%s", x+1, y+1);
	int n = strlen(x + 1), m = strlen(y + 1);
	int px[N] = {0}, py[N] = {0};
	for (int i = 1; i <= n; i ++) {
		px[i] = 0;
		for (int j = i - 1; j >= 1; j --) {
			if (x[j] == x[j+1]) {
				px[i] = j; break;
			}
		}
	}
	for (int i = 1; i <= m; i ++) {
		py[i] = 0;
		for (int j = i - 1; j >= 1; j --) {
			if (y[j] == y[j+1]) {
				py[i] = j; break;
			}
		}
	}

	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= m; j ++) {
			if (i == 0 && j == 0) continue;
			if (i >= 1 && x[i] != y[j]) add(dp[i][j][0], j - py[j]);
			if (j >= 1 && y[j] != x[i]) add(dp[i][j][1], i - px[i]);


			if (i >= 1) {
				if (i>=2 && j>=1 && x[i] != x[i-1])
					add(dp[i][j][0], dp[i-1][j][0]);
				if (j>=1 && i>=2 && x[i] != y[j])
					add(dp[i][j][0], dp[i-1][j][1]);
			}
			if (j >= 1) {
				if (j>=2 && i>=1 && y[j] != y[j-1])
					add(dp[i][j][1], dp[i][j-1][1]);
				if (i>=1 && j>=2 && y[j] != x[i])
					add(dp[i][j][1], dp[i][j-1][0]);
			} 
	
			//printf("dp[%d][%d] = %lld %lld\n", i, j, dp[i][j][0], dp[i][j][1]);
		}
		
	}
	LL ans = 0;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) for (int k = 0; k < 2; k ++) add(ans, dp[i][j][k]);
	printf("%lld\n", ans);
}