#include <bits/stdc++.h>
using namespace std;
int n , x , y , l[2200][2200] , r[2200][2200];
long double dp[2200][2200] , a[2200] , b[2200] , c[2200] , ans , eps = 1e-9;
long double A( long double x )
{
	return (x < 0 ? -x : x);
}
void binary( long double L , long double R )
{
	if(R - L <= eps) return ;
	long double mid = (L + R) / 2;
	memset(dp , -0x7f / 3 , sizeof(dp)); dp[0][0] = l[0][0] = r[0][0] = 0;
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 0 ; j <= i ; j++ )
		{
			l[i][j] = 1e9; r[i][j] = 0;
			if(i > j)
			{
				if(dp[i - 1][j] > dp[i][j])
				{
					dp[i][j] = dp[i - 1][j]; 
					l[i][j] = l[i - 1][j]; r[i][j] = r[i - 1][j]; 
				}
				if(A(dp[i][j] - dp[i - 1][j]) <= eps)
				{
					l[i][j] = min(l[i][j] , l[i - 1][j]); 
					r[i][j] = max(r[i][j] , r[i - 1][j]); 
				}
				if(dp[i - 1][j] + b[i] - mid > dp[i][j])
				{
					dp[i][j] = dp[i - 1][j] + b[i] - mid; 
					l[i][j] = l[i - 1][j] + 1; r[i][j] = r[i - 1][j] + 1; 
				}
				if(A(dp[i][j] - (dp[i - 1][j] + b[i] - mid)) <= eps)
				{
					l[i][j] = min(l[i][j] , l[i - 1][j] + 1); 
					r[i][j] = max(r[i][j] , r[i - 1][j] + 1); 
				}
			}
			if(j) 
			{
				if(dp[i - 1][j - 1] + a[i] > dp[i][j])
				{
					dp[i][j] = dp[i - 1][j - 1] + a[i]; 
					l[i][j] = l[i - 1][j - 1]; r[i][j] = r[i - 1][j - 1]; 
				}
				if(A(dp[i][j] - (dp[i - 1][j - 1] + a[i])) <= eps)
				{
					l[i][j] = min(l[i][j] , l[i - 1][j - 1]); 
					r[i][j] = max(r[i][j] , r[i - 1][j - 1]); 
				}
				if(dp[i - 1][j - 1] + c[i] - mid > dp[i][j])
				{
					dp[i][j] = dp[i - 1][j - 1] + c[i] - mid; 
					l[i][j] = l[i - 1][j - 1] + 1; r[i][j] = r[i - 1][j - 1] + 1; 
				}
				if(A(dp[i][j] - (dp[i - 1][j - 1] + c[i] - mid)) <= eps)
				{
					l[i][j] = min(l[i][j] , l[i - 1][j - 1] + 1); 
					r[i][j] = max(r[i][j] , r[i - 1][j - 1] + 1); 
				}
			}
		}
	}
//	cerr << r[3][2] << endl;
	if(l[n][x] <= y) 
	{
//		cerr << l[n][x] << ' ' << r[n][x] << ' ' << dp[n][x] << ' ' << mid << ' ' << dp[n][x] + min(r[n][x] , y) * mid << endl;
		ans = max(ans , dp[n][x] + min(r[n][x] , y) * mid) , binary(L , mid);
	}
	else binary(mid , R);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &x , &y);
	for(int i = 1 ; i <= n ; i++ ) scanf("%Lf" , &a[i]);
	for(int i = 1 ; i <= n ; i++ ) scanf("%Lf" , &b[i]) , c[i] = a[i] + b[i] - a[i] * b[i];
	binary(0 , 2);
	printf("%.5Lf" , ans);
	return 0;
} 
/*
5 3 3
0.00 0.00 0.00 0.00 0.00  
0.00 0.00 0.00 0.00 0.00  
*/