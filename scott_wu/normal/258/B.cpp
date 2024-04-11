#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int M;
int dp[2][12][12]; // at max / cur dig / nluck
int dig[12];
int nluck[12];
ll ans;

void solve (int nd)
{
	int num[6];
	for (int i = 0; i < 1000000; i++)
	{
		int temp = i, sum = 0;
		for (int j = 0; j < 6; j++)
		{
			num[j] = temp % 10;
			temp /= 10;
			sum += num[j];
		}
		
		if (sum < nd)
		{
			ll good = nluck[nd];
			for (int j = 0; j < 6; j++)
			{
				good = (good * nluck[num[j]]) % MOD;
				nluck[num[j]]--;
			}
			for (int j = 0; j < 6; j++)
				nluck[num[j]]++;
			
			ans = (ans + good) % MOD;
		}
	}
}

int main()
{
	ans = 0;
	
	cin >> M;
	for (int i = 0; i < 10; i++)
	{
		dig[i] = M % 10;
		M /= 10;
	}
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 12; j++)
			for (int k = 0; k < 12; k++)
				dp[i][j][k] = 0;
	dp[1][10][0] = 1;
	
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (k == 4 || k == 7)
					dp[0][i][j+1] += dp[0][i+1][j];
				else
					dp[0][i][j] += dp[0][i+1][j];
			}
		}
		
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < dig[i]; k++)
			{
				if (k == 4 || k == 7)
					dp[0][i][j+1] += dp[1][i+1][j];
				else
					dp[0][i][j] += dp[1][i+1][j];
			}
			
			if (dig[i] == 4 || dig[i] == 7)
				dp[1][i][j+1] += dp[1][i+1][j];
			else
				dp[1][i][j] += dp[1][i+1][j];
		}
	}
	
	for (int i = 0; i < 12; i++)
		nluck[i] = dp[0][0][i] + dp[1][0][i];
	nluck[0]--;
	
	for (int i = 1; i < 10; i++)
		solve (i);
	cout << ans << "\n";
	return 0;
}