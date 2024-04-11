#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#define ll long long int

using namespace std;

const ll mod = 1000000007;

int m;
ll x[2000];
ll y[2000];
ll c[2000][2000];
ll dp[2000][2000];
int n = 0;
int sum[2000];

int main()
{
	
	cin >> m;
	sum[0] = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> x[i];
		n += x[i];
		sum[i + 1] = n;
	}
	for (int i = 0; i < m; i++)
		cin >> y[i];
	c[0][0] = 1;
	for (int i = 1; i < 2000; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}

	memset(dp, 0, sizeof(dp));
	
	dp[0][0] = 1;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			if (dp[i][j] == 0) continue;
//			dp[i][j] = (dp[i][j] * c[n - sum[i]][j + x[i]]) % mod; 

			for (int g = j + x[i] - y[i]; g <= j + x[i]; g++)
				dp[i + 1][g] = (dp[i + 1][g] + (dp[i][j] * c[j + x[i]][g]) % mod) % mod;
		}

	}

/*	for (int i = 0; i < m; i++)
	{
		cout << "\n";
		for (int j = 0; j < 100; j++)
		{
			cout << dp[i][j] << " ";
	
		}
	}*/
	ll ans = 0;
	for (int i = 0; i <= y[m - 1] - x[m - 1]; i++)
		ans = (ans + dp[m - 1][i]) % mod;
	for (int i = 0; i < m; i++)
		ans = (ans * c[n - sum[i]][x[i]]) % mod;
	cout << ans;





	
}