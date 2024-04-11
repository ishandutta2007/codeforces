#include<bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
struct item
{
	int num , id;
	item operator + ( const item &x ) const
	{
		if(num > x.num) return (*this);
		return x;
	}
	
} t[2200000];
int n , a[550000] , b[550000] , c[550000] , fa[550000] , vis[550000] , tot;
vector< int > id;
void build( int l , int r , int id )
{
	if(l == r)
	{
		t[id] = (item){c[l] , l};
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	t[id] = t[lson] + t[rson];
	return ;
}
void upd( int l , int r , int a , int id )
{
	if(r < a || a < l) return ;
	if(l == r)
	{
		t[id].num = 0;
		return ;
	}
	int mid = l + r >> 1;
	upd(l , mid , a , lson); upd(mid + 1 , r , a , rson); 
	t[id] = t[lson] + t[rson];
}
item ask( int l , int r , int a , int b , int id )
{
	if(r < a || b < l) return (item){0 , 0};
	if(a <= l && r <= b) return t[id];
	int mid = l + r >> 1;
	return ask(l , mid , a , b , lson) + ask(mid + 1 , r , a , b , rson);
}
void dfs( int u )
{
//	cerr << "in: " << u << endl;
	vis[u] = 1;
	item qwq = ask(1 , n , 1 , b[u] - 1 , 1);
	while(qwq.num > u)
	{
		upd(1 , n , qwq.id , 1); 
		if(!vis[qwq.id]) dfs(qwq.id);
		qwq = ask(1 , n , 1 , b[u] - 1 , 1);
	}
	if(c[u] <= n && !vis[c[u]]) dfs(c[u]);
	a[u] = ++tot;
//	cerr << "out: " << u << endl;
	return ;
}
int main()
{
	memset(c , 0x7f / 3 , sizeof(c));
	scanf("%d" , &n); vis[n + 1] = 1;
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%d" , &b[i]); 
		if(b[i] == -1) b[i] = n + 1;
		c[b[i]] = i;
	}
	build(1 , n , 1);
	for(int i = 1 ; i <= n ; i++ )
		if(!vis[i]) dfs(i);
	for(int i = 1 ; i <= n ; i++ ) printf("%d " , a[i]);
	return 0;
}
/*
*/