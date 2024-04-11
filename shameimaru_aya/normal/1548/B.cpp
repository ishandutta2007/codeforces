#include<bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int T , n , maxx;
long long c[880000] , a[880000] , b[880000];
void build( int l , int r , int id )
{
	if(l > r) return ;
	if(l == r)
	{
		c[id] = (a[l] < 0 ? -a[l] : a[l]);
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	c[id] = __gcd(c[lson] , c[rson]);
}
long long ask( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return 0;
	if(a <= l && r <= b) return c[id];
	int mid = l + r >> 1;
	long long lans = ask(l , mid , a , b , lson) , rans = ask(mid + 1 , r , a , b , rson);
	if(!lans) return rans;
	if(!rans) return lans;
	return __gcd(lans , rans);
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); maxx = 1;
		for(int i = 1 ; i <= n ; i++ ) scanf("%lld" , &b[i]);
		for(int i = 1 ; i < n ; i++ ) a[i] = b[i + 1] - b[i]; n--;
		build(1 , n , 1);
		for(int i = 1 ; i <= n ; i++ )
		{
			int l = i , r = n , ans = i - 1;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(ask(1 , n , i , mid , 1) != 1) ans = mid , l = mid + 1;
				else r = mid - 1;
			}
			maxx = max(maxx , ans - i + 2);
		}
		printf("%d\n" , maxx);
	}
    return 0;
}
/*
1
8
465 55 3 54 234 12 45 78 

*/