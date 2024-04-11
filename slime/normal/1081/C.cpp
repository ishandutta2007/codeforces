#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define ll long long
#define mod 998244353
using namespace std;
int n, m, k;
ll dp[maxn][maxn];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = n + 1; i >= 1; i--)
		for(int j = 0; j <= k; j++)
		{
			if(i == n + 1)
				if(j == k) dp[i][j] = 1;
				else dp[i][j] = 0;
			else
			{
				if(i == 1)
					dp[i][j] = m * dp[i + 1][j] % mod;
				else
					dp[i][j] = (m - 1) * dp[i + 1][j + 1] + dp[i + 1][j],
					dp[i][j] %= mod;
			}
		}
	printf("%lld\n", dp[1][0]);
	return 0;
}