#include <bits/stdc++.h>
#define pr pair< int , int > 
#define F first
#define S second
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int n , m , p , k , a[220000] , x , l , r , opt , lazy[880000];
struct item
{
	pr a[7];
	item operator + ( const item &x ) const
	{
		item ans = x;
		for(int i = 1 ; i <= k ; i++ )
		{
			int minn = a[i].S , f = 0 , id = 0;
			for(int j = 1 ; j <= k ; j++ )
			{
				minn = min(minn , ans.a[j].S);
				if(a[i].F == ans.a[j].F)
				{
					f = 1;
					ans.a[j].S += a[i].S;
					break;
				}
			}
			if(f) continue;
			for(int j = 1 ; j <= k ; j++ )
			{
				ans.a[j].S -= minn;
				if(!ans.a[j].S) id = j;
			}
			if(id) ans.a[id] = a[i] , ans.a[id].S -= minn;
		}
		return ans;
	}
	void clear()
	{
		for(int i = 1 ; i <= k ; i++ ) a[i] = {0 , 0};
	}
} c[880000] , emp;
void build( int l , int r , int id )
{
	if(l == r)
	{
		c[id].a[1] = {a[l] , 1};
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	c[id] = c[lson] + c[rson];
}
void push_down( int l , int r , int id )
{
	if(!lazy[id]) return ;
	int mid = l + r >> 1;
	lazy[lson] = lazy[id]; c[lson].clear(); c[lson].a[1] = {lazy[id] , mid - l + 1};
	lazy[rson] = lazy[id]; c[rson].clear(); c[rson].a[1] = {lazy[id] , r - mid};
	lazy[id] = 0;
}
void upd( int l , int r , int a , int b , int d , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		lazy[id] = d;
		c[id].clear(); c[id].a[1] = {d , r - l + 1};
		return ;
	}
	push_down(l , r , id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , d , lson); upd(mid + 1 , r , a , b , d , rson); 
	c[id] = c[lson] + c[rson];
}
item ask( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return emp;
	if(a <= l && r <= b) return c[id];
	push_down(l , r , id);
	int mid = l + r >> 1;
	return ask(l , mid , a , b , lson) + ask(mid + 1 , r , a , b , rson); 
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m , &p); k = 100 / p;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	build(1 , n , 1);
	while(m--)
	{
		scanf("%d%d%d" , &opt , &l , &r);
		if(opt == 1)
		{
			scanf("%d" , &x);
			upd(1 , n , l , r , x , 1);
		}
		else 
		{
			item ans = ask(1 , n , l , r , 1);
			printf("%d " , k);
			for(int i = 1 ; i <= k ; i++ ) printf("%d " , ans.a[i].F);
			printf("\n");
		}
	}
	return 0; 
}
/*
*/