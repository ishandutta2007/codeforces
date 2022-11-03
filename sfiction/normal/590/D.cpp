#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 150 + 5;
const int INF = 1 << 30;

int n, K, s;
int a[MAXN];
int dp[2][MAXN][MAXN * MAXN];

int solve(){
	int ret = INF;
	int m = min(s, (n - K) * K);

	for (int i = 0; i <= K; ++i)
		for (int j = 0; j <= m; ++j)
			dp[1][i][j] = INF;
	dp[1][0][m] = 0;

	for (int i = 0; i < n; ++i){
		int (&f)[MAXN][MAXN * MAXN] = dp[i + 1 & 1];
		int (&g)[MAXN][MAXN * MAXN] = dp[i & 1];
		int KK = min(i + 1, K);

		for (int j = 0; j <= K; ++j)
			for (int k = 0; k <= m; ++k)
				g[j][k] = f[j][k];

		for (int j = 0; j < KK; ++j)
			for (int k = i - j; k <= m; ++k)
				g[j + 1][k - (i - j)] = min(g[j + 1][k - (i - j)], f[j][k] + a[i]);

		for (int k = 0; k <= m; ++k)
			ret = min(ret, g[K][k]);

		/*
		for (int j = 0; j <= KK; ++j)
			for (int k = 0; k <= m; ++k)
				printf("(%d,%d) %d %d\n", j, k, f[j][k], g[j][k]);
		puts("---------");
		*/
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &K, &s);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	printf("%d\n", solve());
	return 0;
}