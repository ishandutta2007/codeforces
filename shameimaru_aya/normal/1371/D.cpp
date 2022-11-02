#include<bits/stdc++.h>
using namespace std;
int T , n , m , a[330][330] , x , y , t , tot;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		if(m % n == 0) printf("0\n");
		else printf("2\n");
		x = 1; y = 1; t = n; tot = 1;
		while(m--)
		{
			a[x][y] = 1;
			t--;
			if(t == 0)
			{
				t = n;
				x = 1;
				y = ++tot;
			}
			else
			{
				x++; if(x > n) x = 1;
				y++; if(y > n) y = 1;
			}
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = 1 ; j <= n ; j++ )
			{
				printf("%d" , a[i][j]);
				a[i][j] = 0;
			}
			printf("\n");
		}
	}
	return 0;
}