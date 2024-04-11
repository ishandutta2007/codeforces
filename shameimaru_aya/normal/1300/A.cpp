#include<bits/stdc++.h>
using namespace std;
int T , n , a[300000] , x , y , ans;;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		ans = x = y = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a[i]);
			if(!a[i]) x++;
			y += a[i];
		}
		y += x , ans += x;
		if(y == 0) y++ , ans++;
		printf("%d\n" , ans);
	}
	return 0;
}
//2 3 4 5 8 13 13 16 17 20