#include <iostream>
#include <vector>
using namespace std;

const int N = 18;
long long dp[1 << N][N];
long long a[N];
long long edge[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < k; i ++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u --;
		v --;
		edge[u][v] = c;
	}
	long long ans = 0;
	for(int i = 0; i < n; i ++)
		dp[(1 << i)][i] = a[i];
	for(int i = 0; i < (1 << n); i ++)
		for(int j = 0; j < n; j ++)
			if((i >> j) & 1)
			{
				int cnt = 0;
				for(int k = 0; k < n; k ++)
					if((i >> k) & 1)
						cnt ++;
					else
						dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] + a[k] + edge[j][k]);
				if(cnt == m)
					ans = max(ans, dp[i][j]);
			}
	cout << ans << '\n';
	return 0;
}