#include<bits/stdc++.h>
using namespace std;
int T , n , m , dp[110][110] , mp[110][110] , ans;
string s;
int main()
{
	cin.tie(0); cout.tie(0);
	scanf("%d" , &T);
	while(T--)
	{
		ans = 0;
		memset(dp , 0 , sizeof(dp));
		scanf("%d%d" , &n , &m); dp[n][m] = 1;
		for(int i = 1 ; i <= n ; i++ )
		{
			cin >> s;
			for(int j = 1 ; j <= m ; j++ )
			{
				mp[i][j] = (s[j - 1] == 'R');
			}
		}
		for(int i = n ; i >= 1 ; i-- )
		{
			for(int j = m ; j >= 1 ; j-- )
			{
				if(i == n && j == m) continue;
				if(!mp[i][j]) dp[i][j] = dp[i + 1][j];
				else dp[i][j] = dp[i][j + 1];
				if(!dp[i][j]) dp[i][j] = 1 , ans++;
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}