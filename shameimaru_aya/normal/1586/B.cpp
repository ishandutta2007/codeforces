#include <bits/stdc++.h>
using namespace std;
int T , n , m , a , b , c , f[110000];
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= n ; i++ ) f[i] = 0;
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d%d" , &a , &b , &c);
			f[b] = 1;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if(!f[i])
			{
				for(int j = 1 ; j <= n ; j++ )
				{
					if(i != j) printf("%d %d\n" , i , j);
				}
				break;
			}
		}
	}
	return 0;
}
/*
*/