#include <iostream>
#include <cstring>
using namespace std;

const int N = 153;
const int M = N * N;
const int Inf = 0x3f3f3f3f;

int dp[2][N][M];
int a[N];

void update(int &a, int b)
{
	if(b == -1)
		return;

	if(a == -1)
		a = b;
	else
		a = min(a, b);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));
	int now = 0;
	dp[0][0][0] = 0;
	for(int i = 0; i < n; i ++)
	{
		int nxt = now ^ 1;
		memset(dp[nxt], -1, sizeof(dp[nxt]));
		for(int j = 0; j <= m; j ++)
			for(int k = 0; k <= i * i; k ++)
			{
				update(dp[nxt][j][k], dp[now][j][k]);
				if(k + (i - j) < M && dp[now][j][k] != -1)
					update(dp[nxt][j + 1][k + (i - j)], dp[now][j][k] + a[i + 1]);
			}
		now = nxt;
	}
	int ans = -1;
	for(int i = 0; i <= n * n && i <= t; i ++)
		update(ans, dp[now][m][i]);

	cout << ans << '\n';
	return 0;
}