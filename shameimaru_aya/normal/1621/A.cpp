#include <bits/stdc++.h> 
using namespace std;
int T , n , m , f[44][44];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		memset(f , 0 , sizeof(f));
		scanf("%d%d" , &n , &m);
		if(m > (n + 1) / 2)
		{
			printf("-1\n");
			continue;
		}
		for(int i = 1 ; i <= m ; i++ )
		{
			f[i * 2 - 1][i * 2 - 1] = 1;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = 1 ; j <=  n ; j++ )
			{
				if(!f[i][j]) printf(".");
				else printf("R");
			}
			printf("\n");
		}
	}
    return 0;
} 
/*
*/