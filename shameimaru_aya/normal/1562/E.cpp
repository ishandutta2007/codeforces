#include <bits/stdc++.h>
using namespace std;
int T , n , lcp[5500][5500] , dp[5500] , ans;
string s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		ans = 0;
		for(int i = n + 1 ; i >= 1 ; i-- )
			for(int j = n + 1 ; j >= 1 ; j-- ) lcp[i][j] = 0;
		scanf("%d" , &n); cin >> s;
		for(int i = n ; i >= 1 ; i-- )
			for(int j = n ; j >= 1 ; j-- )
				lcp[i][j] = s[i - 1] == s[j - 1] ? lcp[i + 1][j + 1] + 1 : 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			dp[i] = n - i + 1;
			for(int j = 1 ; j < i ; j++ ) 
			{
				if(i + lcp[i][j] <= n && s[j + lcp[i][j] - 1] < s[i + lcp[i][j] - 1]) 
					dp[i] = max(dp[i] , dp[j] + n - i + 1 - lcp[i][j]);
			}
			ans = max(ans , dp[i]);
//			cerr << dp[i] << ' ';
		}
//		cerr << endl;
		printf("%d\n" , ans);
	}
	
	return 0;
}
/*
*/