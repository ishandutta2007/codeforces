#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int T , n , q , a[220000] , c2[880000] , lazy2[880000] , t[880000] , opt , x , y , z;
set< int > gg;
void build( int l , int r , int id )
{
	lazy2[id] = 0; 
	if(l == r)
	{
		t[id] = 1e9; c2[id] = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	t[id] = min(t[lson] , t[rson]);
	c2[id] = c2[lson] + c2[rson];
}
void push_down2( int id )
{
	if(!lazy2[id]) return ;
	c2[lson] = c2[rson] = 1; lazy2[lson] = lazy2[rson] = 1; lazy2[id] = 0;
}
void upd3( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		c2[id] = 1; lazy2[id] = 1;
		return ;
	}
	push_down2(id);
	int mid = l + r >> 1;
	upd3(l , mid , a , b , lson); upd3(mid + 1 , r , a , b , rson); 
	c2[id] = c2[lson] + c2[rson];
	return ;
}
void upd2( int l , int r , int a , int b , int id )
{
	if(a < l || r < a) return ;
	if(a <= l && r <= a)
	{
		t[id] = min(t[id] , b);
		return ;
	}
	int mid = l + r >> 1;
	upd2(l , mid , a , b , lson); upd2(mid + 1 , r , a , b , rson); 
	t[id] = min(t[lson] , t[rson]);
	return ;
}
int ask2( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return 1e9;
	if(a <= l && r <= b) return t[id];
	int mid = l + r >> 1;
	return min(ask2(l , mid , a , b , lson) , ask2(mid + 1 , r , a , b , rson));
}
int ask3( int l , int r , int a , int b , int id )
{
	if(b < l || r < a) return 0;
	if(a <= l && r <= b) return c2[id];
	push_down2(id);
	int mid = l + r >> 1;
	return ask3(l , mid , a , b , lson) + ask3(mid + 1 , r , a , b , rson);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	T = 1;
	while(T--)
	{
		scanf("%d%d" , &n , &q); build(1 , n , 1); gg.clear();
		for(int i = 1 ; i <= n ; i++ ) gg.insert(i); 
		gg.insert(1e9); gg.insert(0);
		while(q--)
		{
			scanf("%d%d" , &opt , &x);
			if(opt == 0)
			{
				scanf("%d%d" , &y , &z);
				if(!z) 
				{
					set< int >::iterator it = gg.lower_bound(x);
					while(*it <= y)
					{
						gg.erase(it);
						it = gg.lower_bound(x);
					}
				}
				else upd2(1 , n , x , y , 1) , upd3(1 , n , x , y , 1);
			}
			else
			{
				int qwq = *gg.lower_bound(x);
				if(qwq != x)
				{
					printf("NO\n");
					continue;
				}
				int l;
				set< int >::iterator it = gg.lower_bound(x);
				it--; l = (*it) + 1;
				int r = ask2(1 , n , l , x , 1);
				qwq = *gg.upper_bound(x);
//				cerr << l << ' ' << r << ' ' << a << endl;
				if(qwq > r && ask3(1 , n , x , x , 1)) printf("YES\n");
				else printf("N/A\n");
			}
		}
	}
	return 0;
}
/*

*/