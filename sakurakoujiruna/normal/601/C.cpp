#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int N = 101;
const int M = 101111;

double dp[N][M];
double sum[N][M];
int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if(m == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
		//a[i] = 2;
	dp[0][0] = m - 1;
	for(int i = 1; i < M; i ++)
		dp[0][i] = 0;
	for(int i = 0; i < M; i ++)
		sum[0][i] = m - 1;
	for(int i = 1; i <= n; i ++)
	{
		dp[i][0] = 0;
		sum[i][0] = 0;
		for(int j = 1; j < M; j ++)
		{
			dp[i][j] = sum[i - 1][j - 1];
			if(j - m - 1 >= 0)
				dp[i][j] -= sum[i - 1][j - m - 1];
			if(j - a[i] >= 0)
				dp[i][j] -= dp[i - 1][j - a[i]];
			dp[i][j] /= m - 1;
			sum[i][j] = sum[i][j - 1] + dp[i][j];
		}
	}

	int s = 0;
	for(int i = 1; i <= n; i ++)
		s += a[i];
	double ans = 0;
	for(int i = 0; i < s; i ++)
		ans += dp[n][i];
	cout << setprecision(15) << ans + 1 << '\n';
	return 0;
}