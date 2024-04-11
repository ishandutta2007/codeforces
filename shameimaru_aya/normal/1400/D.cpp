#include<bits/stdc++.h>
using namespace std;
int T , n , a[3300];
long long num[3300] , b[3300][3300] , h[3300][3300] , sum , ans;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		ans = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			num[i] = 0; 
			for(int j = 1 ; j <= n ; j++ ) b[i][j] = h[i][j] = 0;
		}
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
		for(int j = 1 ; j <= n ; j++ )
		{
			for(int i = 1 ; i <= n ; i++ ) b[i][j] = b[i - 1][j] + (a[i] == j);
			for(int i = n ; i >= 1 ; i-- ) h[i][j] = h[i + 1][j] + (a[i] == j);
		}
		for(int i = 1 ; i <= n ; i++ ) 
			for(int j = 1 ; j <= n ; j++ ) num[i] += b[i - 1][j] * h[i + 1][j];
		for(int i = 1 ; i <= n ; i++ )
		{
			sum = num[i + 1];
			for(int j = i + 1 ; j <= n ; j++ )
			{
				if(a[i] == a[j]) ans += num[j] - sum;
				sum -= b[i][a[j + 1]];
			}
		}
		printf("%lld\n" , ans);
	}
	
    return 0;
}
/*

*/