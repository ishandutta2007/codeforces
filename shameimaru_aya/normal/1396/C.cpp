#include<bits/stdc++.h>
using namespace std;
long long n , cst1 , num[1100000] , a , b , c , d;
long long ttt[2][1100000] , dp[2][1100000] , ans;
int main()
{
	scanf("%lld%lld%lld%lld%lld" , &n , &a , &b , &c , &d);
	for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &num[i]);
	dp[1][0] = ttt[1][0] = 1e18;
	for(int i = 1 ; i <= n ; i++ )
	{
		cst1 = min(b , a * (num[i] + 1));
		if(i != n)
		dp[0][i] = min(dp[0][i - 1] + num[i] * a + c , 
					   dp[1][i - 1] + min(num[i] * a + c , a + cst1));
		else 
		dp[0][i] = min(dp[0][i - 1] + num[i] * a + c , 
					   dp[1][i - 1] + min(num[i] * a + c - d , a + cst1));
		dp[1][i] = dp[0][i - 1] + 2ll * d + a + cst1;
//		cerr << dp[0][i] + (i - 1) * d << ' ' << dp[1][i] + (i - 1) * d << endl;
		if(i != n)
		{
			ttt[0][i] = ttt[0][i - 1] + num[i] * a + c;
			if(ttt[0][i] < 0) ttt[0][i] = 1e18;
			ttt[1][i] = min(ttt[0][i - 1] , ttt[1][i - 1] + d) + min(a + cst1 , num[i] * a + c);
		}
		else
		{
			ttt[0][i] = ttt[0][i - 1] + num[i] * a + c;
			if(ttt[0][i] < 0) ttt[0][i] = 1e18;
			ttt[1][i] = min(ttt[0][i - 1] , ttt[1][i - 1] + d) + min(a + cst1 + 2 * d , num[i] * a + c);
		}
	}
	ans = min(min(ttt[0][n] , ttt[1][n]) , min(dp[0][n] , dp[1][n])) + (n - 1) * d;
	printf("%lld" , ans);
    return 0;
}