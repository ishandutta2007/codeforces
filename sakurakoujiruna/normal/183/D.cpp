#include <bits/stdc++.h>
using namespace std;

const int N = 3011, M = 311;

int p[M][N];
double dp[M][N];
double acc[M];

double nxt[N];
void solve(int p[], double dp[], double &acc, int n) {
	fill(nxt, nxt + n + 1, 0);
	for(int i = 1; i <= n; i ++)
		nxt[i] = (dp[i - 1] * p[i] + nxt[i - 1] * (1000 - p[i])) / 1000;
	copy(nxt, nxt + n + 1, dp);
	acc += dp[n];
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			scanf("%d", &p[j][i]);
	for(int i = 1; i <= m; i ++) {
		dp[i][0] = 1;
		for(int j = 1; j <= n; j ++)
			dp[i][j] = dp[i][j - 1] * (1000 - p[i][j]) / 1000;
		acc[i] += dp[i][n];
	}

	double ans = 0;
	for(int i = 1; i <= n; i ++) {
		int buy = 1;
		for(int j = 2; j <= m; j ++)
			if(acc[j] < acc[buy])
				buy = j;
		ans += 1 - acc[buy];
		solve(p[buy], dp[buy], acc[buy], n);
	}

	cout << fixed << setprecision(12) << ans << '\n';
	return 0;
}