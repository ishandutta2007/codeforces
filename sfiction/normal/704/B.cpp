#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5E3 + 10;
const ll INF = 1ll << 60;

int n, S, T;
ll dp[2][MAXN];
int x[MAXN], a[MAXN][4];

int main(){
	scanf("%d%d%d", &n, &S, &T);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	for (int j = 0; j < 4; ++j)
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i][j]);
	fill_n(dp[0] + 1, n + 1, INF);
	for (int i = 1; i <= n; ++i){
		ll (&f)[MAXN] = dp[i - 1 & 1], (&g)[MAXN] = dp[i & 1];

		fill_n(g, n + 2, INF);
		if (S < i && T < i)
			f[1] = INF;
		if (i == S){
			for (int j = 1; j <= i; ++j){
				g[j] = min(g[j], f[j] + x[i] + a[i][2]);
				g[j] = min(g[j], f[j - 1] - x[i] + a[i][3]);
			}
		}
		else if (i == T){
			for (int j = 1; j <= i; ++j){
				g[j] = min(g[j], f[j] + x[i] + a[i][0]);
				g[j] = min(g[j], f[j - 1] - x[i] + a[i][1]);
			}
		}
		else{
			for (int j = 1; j <= i; ++j){
				g[j] = min(g[j], f[j + 1] + 2 * x[i] + a[i][0] + a[i][2]);
				g[j] = min(g[j], f[j - 1] - 2 * x[i] + a[i][1] + a[i][3]);
				if (j > 1 || i < T)
					g[j] = min(g[j], f[j] + a[i][0] + a[i][3]);
				if (j > 1 || i < S)
					g[j] = min(g[j], f[j] + a[i][1] + a[i][2]);
			}
		}
	}
	printf("%I64d\n", dp[n & 1][1]);
	return 0;
}