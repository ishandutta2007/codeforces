#include <bits/stdc++.h> 
using namespace std;
int T , n;
long long ans , a[550][550];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); ans = 1e18;
		for(int i = 1 ; i <= 2 * n ; i++ )
			for(int j = 1 ; j <= 2 * n ; j++ )
				scanf("%lld" , &a[i][j]);
		ans = min(a[1][n + 1] , a[1][2 * n]);
		ans = min(ans , a[n][n + 1]);
		ans = min(ans , a[n][2 * n]);
		ans = min(ans , a[n + 1][1]);
		ans = min(ans , a[n + 1][n]);
		ans = min(ans , a[n + n][1]);
		ans = min(ans , a[n + n][n]);
		for(int i = n + 1 ; i <= 2 * n ; i++ )
			for(int j = n + 1 ; j <= 2 * n ; j++ ) ans += a[i][j];
		printf("%lld\n" , ans);
	}
    return 0;
} 
/*
*/