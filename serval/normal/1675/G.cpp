#include <bits/stdc++.h>

using namespace std;

const int N = 255;
const int MAX = 1e8;

int n, m;
int a[N], pre[N];
int f[N][N][N];
int ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= m; k++)
				f[i][j][k] = MAX;
	f[0][m][0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= m - j; k++)
				for (int l = k; l <= j; l++)
					f[i][j - l][l] = min(f[i][j - l][l], f[i - 1][j][k] + abs(j - l - pre[n - i]));
	ans = MAX;
	for (int i = 0; i <= m; i++)
		ans = min(ans, f[n][0][i]);
	printf("%d\n", ans);
	return 0;
}