#include <cstdio>
#include <cstring>

typedef long long int64;

const int maxn = 300005;
int n, x, a[maxn];
int64 dp[maxn][5];

void upd(int64 &x, int64 y)
{
	if (x < y) x = y;
}

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	memset(dp, -0x3f, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= 4; ++j)
			for (int k = j; k <= 4; ++k)
				upd(dp[i + 1][k], dp[i][j] + (k == 0 || k == 4 ? 0 : k == 1 || k == 3 ? a[i + 1] : 1LL * a[i + 1] * x));
	printf("%lld\n", dp[n + 1][4]);
	return 0;
}