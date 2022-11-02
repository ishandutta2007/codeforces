#include <bits/stdc++.h>
using namespace std;
int n , m , sa , sb , a[10] , b[10] , c[10][10] , st[10] , dp[7][5][5][5][5][5][5] , ans = 1e9;
void trans( int k , int st[10] )
{
	int trs[10];
	memset(trs , 0 , sizeof(trs));
	for( trs[1] = 0 ; trs[1] <= st[1] ; trs[1]++ )
		for( trs[2] = 0 ; trs[2] <= st[2] ; trs[2]++ )
			for( trs[3] = 0 ; trs[3] <= st[3] ; trs[3]++ )
				for( trs[4] = 0 ; trs[4] <= st[4] ; trs[4]++ )
					for( trs[5] = 0 ; trs[5] <= st[5] ; trs[5]++ )
					{
						trs[6] = a[k] - (trs[1] + trs[2] + trs[3] + trs[4] + trs[5]);
//						cerr << trs[6] << endl;
						if(trs[6] >= 0 && trs[6] <= st[6])
						{
							int val = dp[k - 1][st[1]][st[2]][st[3]][st[4]][st[5]][st[6]];
							for(int i = 1 ; i <= 6 ; i++ ) 
								if(trs[i]) val += c[k][i];
							#define qwq(i) (st[i] - trs[i])
							#define NOW dp[k][qwq(1)][qwq(2)][qwq(3)][qwq(4)][qwq(5)][qwq(6)]
							NOW = min(NOW , val);
							#undef qwq
							#undef NOW
						}
					}
							
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , sa += a[i];
	for(int i = 1 ; i <= m ; i++ ) scanf("%d" , &b[i]) , sb += b[i];
	for(int i = 1 ; i <= n ; i++ ) 
		for(int j = 1 ; j <= m ; j++ ) scanf("%d" , &c[i][j]);
	if(sa > sb)
	{
		printf("-1");
		return 0;
	}
	memset(dp , 0x7f / 3 , sizeof(dp));
	dp[0][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]] = 0;
	for(int i = 1 ; i <= n ; i++ )
		for( st[1] = 0 ; st[1] <= b[1] ; st[1]++ )
			for( st[2] = 0 ; st[2] <= b[2] ; st[2]++ )
				for( st[3] = 0 ; st[3] <= b[3] ; st[3]++ )
					for( st[4] = 0 ; st[4] <= b[4] ; st[4]++ )
						for( st[5] = 0 ; st[5] <= b[5] ; st[5]++ )
							for( st[6] = 0 ; st[6] <= b[6] ; st[6]++ ) trans(i , st);
	for( st[1] = 0 ; st[1] <= b[1] ; st[1]++ )
		for( st[2] = 0 ; st[2] <= b[2] ; st[2]++ )
			for( st[3] = 0 ; st[3] <= b[3] ; st[3]++ )
				for( st[4] = 0 ; st[4] <= b[4] ; st[4]++ )
					for( st[5] = 0 ; st[5] <= b[5] ; st[5]++ )
						for( st[6] = 0 ; st[6] <= b[6] ; st[6]++ )
							ans = min(ans , dp[n][st[1]][st[2]][st[3]][st[4]][st[5]][st[6]]);
	printf("%d" , ans);
	return 0;
}
/*

*/