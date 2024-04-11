#include <cstdio>

const int MAXN = 1E2 + 10, MAXM = 1E3 + 10;

double f[MAXN][MAXM * MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if (m == 1){
		puts("1");
		return 0;
	}

	double p = 1.0 / (m - 1);
	int sum = 0;
	f[0][0] = m - 1;
	for (int w, i = 1; i <= n; ++i){
		int limit = i * (m - 1);
		scanf("%d", &w);
		sum += --w;

		double cnt = 0.0;
		for (int j = 0; j < m; ++j)
			f[i][j] = (cnt += f[i - 1][j]) * p;
		for (int j = m; j <= limit; ++j)
			f[i][j] = (cnt += f[i - 1][j] - f[i - 1][j - m]) * p;
		for (int j = w; j <= limit; ++j)
			f[i][j] -= f[i - 1][j - w] * p;
	}
	double ans = 1.0;
	for (int i = 0; i < sum; ++i)
		ans += f[n][i];
	printf("%.10lf\n", ans);
	return 0;
}