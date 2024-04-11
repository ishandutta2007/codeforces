#include<bits/stdc++.h>

using namespace std;

const long long N = 5000 + 7;
const long long mod = 1e9 + 7;

long long dp[N][3];

int main ()
{
	long long n, a, b, k;

	cin >> n >> a >> b >> k;

	if(a >= b)
	{
		a = n + 1 - a;
		b = n + 1 - b;
	}

	for(long long i = 1; i < b; i++)
		dp[i][0] = 1;

	for(long long j = 1; j <= k; j++)
	{
		for(long long i = 1; i < b; i++)
			dp[i][j%2]=0;

		for(long long i = 1; i < b; i++)
		{
			dp[1][j%2] += dp[i][(j+1)%2];
			dp[min(b,(i+b+1)/2)][j%2] -= dp[i][(j+1)%2];
			dp[i][j%2] -= dp[i][(j+1)%2];
			dp[i+1][j%2] += dp[i][(j+1)%2];
		}

		for(long long i = 1; i < b; i++)
			dp[i][j%2] += dp[i-1][j%2];

		for(long long i = 1; i < b; i++)
			dp[i][j%2] %= mod;

		//for(long long i = 1; i <= n; i++)
		//	cout << dp[i][j%2] << ' ';
		//cout<<endl;
	}

	cout<<dp[a][k%2]<<"\n";

	return 0;
}
/*
10 1 10 2
*/