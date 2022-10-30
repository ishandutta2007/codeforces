#include <bits/stdc++.h>
using namespace std;
int T , n , a[1100][1100] , r[1100][1100] , s[1100] , sum;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		memset(s , 0 , sizeof(s)); sum = 0;
		for(int i = 1 ; i <= n ; i++ )
			for(int j = 1 ; j <= n ; j++ ) r[i][j] = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = 1 ; j <= n ; j++ ) 
			{
				scanf("%d" , &a[i][j]); r[i][min(j , n + 1 - j)] ^= a[i][j];
			}
		}
		for(int i = 1 ; i <= n ; i++ )
			for(int j = n ; j >= 1 ; j-- ) r[i][j] ^= r[i][j + 1];
		for(int i = 1 ; i <= n / 2 ; i++ )
		{
			s[i] = s[i - 1];
			for(int j = i ; j <= n - i + 1 ; j++ ) s[i] ^= r[j][i];
			sum ^= s[i];
//			cerr << s[i] << endl;
		}
		for(int i = 2 ; i <= n ; i += 2 )
		{
			for(int j = 1 ; j < 1 + i ; j += 2 ) sum ^= a[i][j];
			for(int j = n ; j > n - i ; j -= 2 ) sum ^= a[i][j];
		}
		printf("%lld\n" , sum);
	}
	return 0;
}
/*
*/