#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long dp[107][2607];
long long dpSum[107][2607];

int main()
{
	string s;
	long long t;

	dp[0][0] = 1;
	dpSum[0][0] = 1;

	for(long long j = 1; j <= 2600; j++)
		dpSum[0][j] = (dpSum[0][j-1] + dp[0][j]) % mod;

	for(long long i = 1; i <= 100; i++)
	{
		for(long long j = 0; j <= 2600; j++)
		{
			if(j >= 26)
				dp[i][j] = (dpSum[i-1][j] - dpSum[i-1][j-26]) % mod;
			else
				dp[i][j] = dpSum[i-1][j];
		}

		dpSum[i][0] = dp[i][0];

		for(long long j = 1; j <= 2600; j++)
			dpSum[i][j] = (dp[i][j] + dpSum[i][j-1]) % mod;
	}

	cin >> t;

	for(t; t > 0; t--)
	{
		cin >> s;

		long long sum = 0;

		for(long long i = 0; i < s.size(); i++)
			sum += s[i]-'a';

		long long res = dp[s.size()][sum] - 1;

		res %= mod;

		while(res < 0)
			res += mod;

		cout << res << "\n";
	}

	return 0;
}