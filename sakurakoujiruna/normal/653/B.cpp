#include <iostream>
using namespace std;

int dp[10][26];

char c[100][4];

int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < q; i ++)
		for(int j = 0; j < 3; j ++)
			cin >> c[i][j];

	dp[1][0] = 1;
	for(int i = 1; i < n; i ++)
		for(int j = 0; j < 26; j ++)
		{
			for(int k = 0; k < q; k ++)
				if(c[k][2] == j + 'a')
					dp[i + 1][c[k][0] - 'a'] += dp[i][j];
				/*
			if(dp[i][j])
				cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
				*/
		}

	int ans = 0;
	for(int i = 0; i < 26; i ++)
		ans += dp[n][i];
	cout << ans << '\n';
	return 0;
}