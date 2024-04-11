#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T = 1 , n , m , tot , las;
long long c1[220000] , c2[220000] , s , ans;
struct item
{
	long long x , y , c;
	bool operator < ( const item &a ) const
	{
		if(c != a.c) return c < a.c;
		return x < a.x;
	}
} node[110000];
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
//	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = 1 ; j <= m ; j++ ) 
			{
				++tot;
				scanf("%lld" , &node[tot].c); node[tot].x = i; node[tot].y = j;
			}
		}
		sort(node + 1 , node + tot + 1);
		for(int i = 1 ; i <= tot ; i++ )
		{
			if(node[i].c != node[i - 1].c)
			{
				las = i - 1; s = 0;
			}
			s += node[i].x;
			ans += node[i].x * (i - las) - s; 
		}
		
		s = 0; las = 0;
		for(int i = 1 ; i <= tot ; i++ ) swap(node[i].x , node[i].y);
		sort(node + 1 , node + tot + 1);
		for(int i = 1 ; i <= tot ; i++ )
		{
			if(node[i].c != node[i - 1].c)
			{
				las = i - 1; s = 0;
			}
			s += node[i].x;
			ans += node[i].x * (i - las) - s; 
		}
		cout << ans;
	}
	return 0;
}
/*
*/