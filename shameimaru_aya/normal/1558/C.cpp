#include <bits/stdc++.h>
using namespace std;
int T , n , p[2200] , a[2200] , f , ans[5500] , tot , id1 , id2;
void find( int x , int y )
{
	for(int i = 1 ; i <= n ; i++ )
	{
		if(a[i] == x) id1 = i;
		if(a[i] == y) id2 = i;
	}
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); f = 0; tot = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a[i]);
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if((i + a[i]) % 2)
			{
				printf("-1\n"); f = 1;
				break;
			}
		}
		if(f) continue;
		for(int i = n ; i >= 3 ; i -= 2 )
		{
			for(int j = 1 ; j <= n ; j++ )
				if(a[j] == i) id1 = j;
			for(int j = 1 ; j <= n ; j++ )
				if(a[j] == i - 1) id2 = j;
				
				ans[++tot] = id1; reverse(a + 1 , a + id1 + 1); find(i , i - 1);
				ans[++tot] = id2 - 1; reverse(a + 1 , a + id2); find(i , i - 1);
				ans[++tot] = i; reverse(a + 1 , a + i + 1);  find(i , i - 1);
				ans[++tot] = id1; reverse(a + 1 , a + id1 + 1);  find(i , i - 1);
				ans[++tot] = i; reverse(a + 1 , a + i + 1);  find(i , i - 1);
			
		}
		printf("%d\n" , tot);
		for(int i = 1 ; i <= tot ; i++ ) printf("%d " , ans[i]);
		printf("\n");
	}
	return 0;
}
/*
4000000 998244353
*/