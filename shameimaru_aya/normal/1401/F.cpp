#include<bits/stdc++.h>
using namespace std;
int n , k , m , opt , tag[20] , okk[1200000];
int son[2][1200000] , a[330000] , dep[1200000];
long long c[1200000];
long long x , y;
void build( int l , int r , int id )
{
	if(l == r)
	{
		c[id] = a[l];
		dep[id] = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , id << 1);
	build(mid + 1 , r , id << 1 | 1);
	son[0][id] = id << 1 , son[1][id] = id << 1 | 1;
	c[id] = c[son[0][id]] + c[son[1][id]];
	dep[id] = dep[son[1][id]] + 1;
	return ;
}
inline void push_down( int k , int id )
{
	if(tag[k] ^ okk[id]) swap(son[0][id] , son[1][id]);
	okk[id] = tag[k];
}
void rep( int l , int r , int a , long long b , int id )
{
	push_down(dep[id] , id);
	if(a < l || r < a) return ;
	if(l == r && l == a)
	{
		c[id] = b;
		return ;
	}
	int mid = l + r >> 1;
	rep(l , mid , a , b , son[0][id]);
	rep(mid + 1 , r , a , b , son[1][id]);
	c[id] = c[son[0][id]] + c[son[1][id]];
}
long long ask( int l , int r , int a , int b , int id )
{
	push_down(dep[id] , id);
	if(b < l || r < a) return 0;
	if(a <= l && r <= b) return c[id];
	int mid = l + r >> 1;
	return ask(l , mid , a , b , son[0][id]) + ask(mid + 1 , r , a , b , son[1][id]);
}
int main()
{
	scanf("%d%d" , &k , &m); n = 1 << k;
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	build(1 , n , 1);
	while(m--)
	{
		scanf("%d" , &opt);
		if(opt == 1)
		{
			scanf("%lld%lld" , &x , &y);
			rep(1 , n , x , y , 1);
		}
		if(opt == 2)
		{
			scanf("%lld" , &x);
			for(int i = 0 ; i <= x ; i++ ) tag[i] ^= 1;
		}
		if(opt == 3)
		{
			scanf("%lld" , &x);
			tag[x + 1] ^= 1;
		}
		if(opt == 4)
		{
			scanf("%lld%lld" , &x , &y);
			printf("%lld\n" , ask(1 , n , x , y , 1));
		}
	}
    return 0;
}