#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E2 + 10, MAXK = 1E3 + 10;
const ll MOD = 1E9 + 7;

int n, K;
int a[MAXN];
ll dp[2][MAXN][MAXK];

int main(){
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	dp[1][0][K] = dp[1][1][K] = 1;
	int n0 = n >> 1;
	for (int i = 1; i < n; ++i){
		ll (&f)[MAXN][MAXK] = dp[i & 1];
		ll (&g)[MAXN][MAXK] = dp[i + 1 & 1];
		int dis = a[i + 1] - a[i];
		for (int j = 0; j <= n0; ++j)
			for (int k1 = 0, k = j * dis; k <= K; ++k1, ++k){
				f[j][k] %= MOD;
//				printf("f[%d][%d][%d] = %I64d\n", i, j, k, f[j][k]);
				g[j][k1] += f[j][k] * (j + 1);
				g[j + 1][k1] += f[j][k];
				if (j)
					g[j - 1][k1] += f[j][k] * j;
			}
		for (int j = 0; j <= n0; ++j)
			for (int k = 0; k <= K; ++k)
				f[j][k] = 0;
	}
	int ans = 0;
	for (int i = 0; i <= K; ++i)
		ans = (ans + dp[n & 1][0][i]) % MOD;
	printf("%d\n", ans);
	return 0;
}