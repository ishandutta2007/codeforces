#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int n , m , x , c[1100000] , l , r , pl;
inline void add( int x , int a )
{
	while(x <= n)
	{
		c[x] += a;
		x += lowbit(x);
	}
	return ;
}
inline int ask( int x )
{
	int ans = 0;
	while(x)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &x) , add(x , 1);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d" , &x);
		if(x < 0)
		{
			x = -x;
			l = 1 , r = n; pl = -1;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(ask(mid) >= x) pl = mid , r = mid - 1;
				else l = mid + 1;
			}
			if(~pl) add(pl , -1);
		}
		else add(x , 1);
	}
	for(int i = 1 ; i <= 1000000 ; i++ ) 
	{
		if(ask(i))
		{
			printf("%d" , i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
/*
*/