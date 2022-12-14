#include <bits/stdc++.h>

using namespace std;



#define N 2525



double dp[2][N][N], dist[N][N];

int x[N], y[N];



int main() {

	//freopen("r.in", "r", stdin);

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i ++) scanf("%d %d", &x[i], &y[i]);

	for (int i = 0; i < n; i ++) for (int j = i + 1; j < n; j ++) {

		dist[i][j] = sqrt(1.0 * (x[i] - x[j]) * (x[i] - x[j]) + 1.0 * (y[i] - y[j]) * (y[i] - y[j]));

		dist[j][i] = dist[i][j];

	}

	for (int d = 2; d < n; d ++) {

		for (int st = 0, en; st < n; st ++) {

			en = (st + d) % n;

			dp[0][st][en] = max(dp[0][(st+1)%n][en] + dist[st][(st+1)%n], dp[1][st][(en-1+n)%n] + dist[st][(en-1+n)%n]);

			dp[1][st][en] = max(dp[0][(st+1)%n][en] + dist[en][(st+1)%n], dp[1][st][(en-1+n)%n] + dist[en][(en-1+n)%n]);

		}

	}

	double ans = 0;

	for (int st = 0; st < n; st ++) for (int en = st + 1; en < n; en ++) {

		ans = max(ans, dist[st][en] + dp[0][st][en] + dp[0][en][st]);

		ans = max(ans, dist[st][en] + dp[1][st][en] + dp[1][en][st]);

	}

	printf("%.10lf\n", ans);



	return 0;

}