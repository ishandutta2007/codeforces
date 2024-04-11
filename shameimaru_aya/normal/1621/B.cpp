#include <bits/stdc++.h> 
using namespace std;
int T , n;
long long l , r , cl , cr , clr , ans , x , y , z;
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); l = cl = cr = 1e18 , clr = 1e18; r = -1e18; 
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%lld%lld%lld" , &x , &y , &z); 
			if(l > x) cl = clr = 1e18;
			if(r < y) cr = clr = 1e18;
			l = min(l , x); r = max(r , y);
			if(l == x) cl = min(cl , z);
			if(r == y) cr = min(cr , z);
			if(l == x && r == y) clr = min(clr , z);
			printf("%lld\n" , min(cl + cr , clr));
		}
	}
    return 0;
} 
/*
*/