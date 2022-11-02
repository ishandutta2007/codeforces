#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T = 1 , n , m , a[2200000] , f[2200000] , ok[2200000] , s[2200000] , mn , gg , tst , tot;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); gg = 0; mn = 1e9;
		for(int i = 1 ; i <= m ; i++ ) f[i] = 0;
		for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , mn = min(mn , a[i]) , f[a[i]] = 1;
		for(int i = 1 ; i <= m ; i++ ) s[i] = s[i - 1] + f[i];
		if(mn != 1)
		{
			printf("No\n");
			continue;
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			if(f[i]) continue;
			for(int j = 1 ; j <= m / i + 2 ; j++ )
			{
				if(f[j] && s[min(m , j * (i + 1) - 1)] - s[min(m , j * i - 1)]) 
				{
					printf("No\n");
					gg = 1;
					break;
				}
			}
			if(gg) break;
		}
		if(!gg) printf("Yes\n");
		for(int i = 1 ; i <= m ; i++ ) s[i] = 0;
	}
	return 0;
}
/*
*/