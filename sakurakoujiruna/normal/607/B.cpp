#include <iostream>
#include <cstring>
using namespace std;

const int N = 511;

int c[N];
int dp[N][N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i ++)
		dp[i][i] = 1;
	for(int i = 1; i < n; i ++)
		if(c[i] == c[i + 1])
			dp[i][i + 1] = 1;
		else
			dp[i][i + 1] = 2;
	for(int len = 3; len <= n; len ++)
		for(int l = 1; l + len - 1 <= n; l ++)
		{
			int r = l + len - 1;
			if(c[l] == c[r])
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			for(int k = l; k < r; k ++)
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
		}
	cout << dp[1][n] << '\n';
	return 0;
}