#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 4E3 + 10, MAXM = 800;
const int INF = 1 << 30;

int a[MAXN][MAXN];
int dp[2][MAXN];
int *f, *g;

void solve(int l, int r, int optL, int optR){
	int m = l + r >> 1, optM = optL;
	g[m] = INF;
	for (int i = min(optR, m) - 1; i >= optL; --i){
		int t = f[i] + a[m][m] + a[i][i] - a[i][m] - a[m][i];
		if (g[m] > t)
			g[m] = t, optM = i;
	}

	if (l < m)
		solve(l, m, optL, optM + 1);
	if (m + 1 < r)
		solve(m + 1, r, optM, optR);
}

char buf[MAXN << 1];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 1; i <= n; ++i){
		gets(buf);
		for (int j = 1; j <= n; ++j){
			a[i][j] = buf[j - 1 << 1] - '0';
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	fill_n(dp[0] + 1, n, INF);
	f = dp[0], g = dp[1];
	for (int i = 1; i <= m; ++i, swap(f, g))
		solve(1, n + 1, i - 1, n);
	printf("%d\n", dp[m & 1][n] >> 1);
	return 0;
}