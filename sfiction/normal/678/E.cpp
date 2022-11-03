#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 18;

int n;
double p[MAXN + 1][MAXN + 1];
double dp[MAXN + 1][1 << MAXN];

double calc(int u, int mask){
	if (!(mask & 1))
		return !(mask | u) + 1.0;
	if (dp[u][mask] > 0.5)
		return dp[u][mask];
	for (int i = 0; i < n; ++i)
		if (mask >> i & 1)
			dp[u][mask] = max(dp[u][mask], calc(u, mask ^ 1 << i) * p[u][i] + calc(i, mask ^ 1 << i) * p[i][u]);
	return dp[u][mask];
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			scanf("%lf", &p[i][j]);
		p[i][n] = 1.0;
	}
	printf("%.12f\n", calc(n, (1 << n) - 1) - 1.0);
	return 0;
}