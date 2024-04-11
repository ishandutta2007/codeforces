#include <bits/stdc++.h>
using namespace std;
int T = 50 , r , n , N , m , p , mp[220000][70] , a , val[100] , tot , pl[100] , dp[33000][20];
int msk[70] , lim , ans;
char str[100];
mt19937 random((unsigned)time(NULL));
int main()
{
	scanf("%d%d%d" , &n , &m , &p); ans = 0; lim = (n + 1) / 2;
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%s" , str + 1);
		for(int j = 1 ; j <= m ; j++ )
			if(str[j] == '1') mp[i][j] = 1;
	}
	while(T--)
	{
		memset(dp , 0 , sizeof(dp));
		tot = 0;
		r = random() % n + 1;
		for(int i = 1 ; i <= m ; i++ ) 
		{
			if(mp[r][i]) 
			{
				pl[++tot] = i;
				val[i] = tot - 1;
			}
			else val[i] = 0;
		}
		N = (1 << tot) - 1;
		for(int i = 1 ; i <= n ; i++ )
		{
			a = 0;
			for(int j = 1 ; j <= tot ; j++ )
				if(mp[i][pl[j]]) a += 1 << (j - 1);
			dp[a][0]++;
		}
		for(int i = N ; i >= 0 ; i-- )
		{
			int sum = 0;
			for(int j = 0 ; j < tot ; j++ )
			{
				sum += dp[i][j];
				if(!(i & (1 << j))) continue;
				dp[i ^ (1 << j)][j] += sum;
			}
			if(sum >= lim && ans < __builtin_popcount(i)) 
			{
				ans = __builtin_popcount(i);
				memset(msk , 0 , sizeof(msk));
				for(int j = 0 ; j < tot ; j++ )
				{
					if(!(i & (1 << j))) continue;
					msk[pl[j + 1]] = 1;
				}
			}
		}
	}
	for(int i = 1 ; i <= m ; i++ ) printf("%d" , msk[i]);
	return 0;
}
/*
*/