#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const ll MOD = 1000000007;

int N, K;
int sl[MAXN];
ll dp[MAXN][MAXN][2]; // [last ind of diff][# of larger substrings so far][1 for larger, 0 for smaller]
ll ps[MAXN]; // partial sum of dp[i][0]

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		char ch; cin >> ch;
		sl[i] = (int) ch - 'a';
	}
	
	for (int i = 0; i < MAXN; i++)
	{
		ps[i] = 0;
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = 0;
	}
	
	for (int i = 0; i < N; i++)
	{
		dp[i][0][0] = 1;
	}
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= K; j++)
		{
			dp[i][j][0] = (dp[i][j][0] + ps[j]) % MOD;
			//if (i + j - N >= 0)
			//	dp[i][j][1] = (dp[i][j][1] + ps[i + j - N]) % MOD;
		}
		
		int cval = i + 1;
		while (cval < N && (cval - i - 1) * (N - cval) <= K)
		{
			int sum = (cval - i - 1) * (N - cval);
			for (int j = 0; j <= K - sum; j++)
				dp[i][j+sum][0] = (dp[i][j+sum][0] + dp[cval][j][1]) % MOD;
			
			cval++;
		}
		
		if (cval < N)
		{
			cval = N - 1;
			while (cval > i && (cval - i - 1) * (N - cval) <= K)
			{
				int sum = (cval - i - 1) * (N - cval);
				for (int j = 0; j <= K - sum; j++)
					dp[i][j+sum][0] = (dp[i][j+sum][0] + dp[cval][j][1]) % MOD;
			
				cval--;
			}
		}
		
		for (int j = 0; j <= K + i - N; j++)
			dp[i][j+N-i][1] = (dp[i][j+N-i][1] + dp[i][j][0]) % MOD;
		for (int j = 0; j <= K; j++)
		{
			dp[i][j][0] = (dp[i][j][0] * sl[i]) % MOD;
			dp[i][j][1] = (dp[i][j][1] * (25 - sl[i])) % MOD;
			ps[j] += dp[i][j][0];
		}
		
		//cout << i << " " << sl[i] << "\n";
	}
	
	ll ans = 0;
	if (K == 0) ans++;
	
	/*cout << "\n";
	for (int j = 0; j < N; j++)
	{
	for (int i = 0; i <= K; i++)
		cout << dp[j][i][0] << " " << dp[j][i][1] << "\n";
	cout << "\n";
	}*/
	
	for (int i = 0; i < N; i++)
	{
		//cout << dp[i][K][0] << " " << dp[i][K][1] << "\n";
		ans = (ans + dp[i][K][0]) % MOD;
		if (K - (i * (N - i)) >= 0)
			ans = (ans + dp[i][K - (i * (N - i))][1]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}

	
	
// if K == 0 add 1 to ans
// modify psn later