#include <bits/stdc++.h>
using namespace std;

const int N = 100233;
const int M = 511;
bool prime[N];
int dp[N];
int mat[M][M];

int main()
{
	ios :: sync_with_stdio(false);
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i < N; i ++)
		if(prime[i])
			for(int j = i * 2; j < N; j += i)
				prime[j] = false;

	for(int i = N - 2; i >= 0; i --)
	{
		dp[i] = dp[i + 1] + 1;
		if(prime[i])
			dp[i] = 0;
	}

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> mat[i][j];

	int ans = 1e9;
	for(int i = 1; i <= n; i ++)
	{
		int sum = 0;
		for(int j = 1; j <= m; j ++)
			sum += dp[mat[i][j]];
		ans = min(ans, sum);
	}
	for(int j = 1; j <= m; j ++)
	{
		int sum = 0;
		for(int i = 1; i <= n; i ++)
			sum += dp[mat[i][j]];
		ans = min(ans, sum);
	}

	cout << ans << '\n';
	return 0;
}