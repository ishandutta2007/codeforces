#include <bits/stdc++.h> 
#define lson id << 1
#define rson id << 1 | 1
using namespace std;
int n , a[110000] , b[110000] , c[440000] , f[110000] , nex[110000] , mex = 1;
vector< int > q[110000] , pl[110000];
void build( int l , int r , int id ) 
{
	c[id] = 1e9;
	if(l == r)
	{
		c[id] = b[l];
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson);
	build(mid + 1 , r , rson);
	return ;
}
void push_down( int id )
{
	if(c[id] == 1e9) return ;
	c[lson] = min(c[lson] , c[id]); c[rson] = min(c[rson] , c[id]); 
	c[id] = 1e9;
	return ;
}
void upd( int l , int r , int a , int b , int d , int id )
{
	if(r < a || b < l) return ;
	if(a <= l && r <= b)
	{
		c[id] = min(c[id] , d);
		return ;
	}
	push_down(id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , d , lson);
	upd(mid + 1 , r , a , b , d , rson);
	return ;
}
int ask( int l , int r , int a , int id )
{
	if(r < a || a < l) return 0;
	if(a <= l && r <= a) return c[id];
	push_down(id);
	int mid = l + r >> 1;
	return ask(l , mid , a , lson) + ask(mid + 1 , r , a , rson);
}
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n + 1 ; i++ ) pl[i].push_back(0);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]) , pl[a[i]].push_back(i);
	for(int i = 1 ; i <= n + 1 ; i++ ) pl[i].push_back(n + 1);
	for(int i = 1 ; i <= n + 1 ; i++ )
	{
		for(int j = 0 ; j < (int)pl[i].size() - 1 ; j++ )
		{
			if(pl[i][j] + 1 <= pl[i][j + 1] - 1) q[pl[i][j] + 1].push_back(pl[i][j + 1] - 1);
			nex[pl[i][j]] = pl[i][j + 1];
		}
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		f[a[i]] = 1;
		while(f[mex]) mex++;
		b[i] = mex;
	}
	build(1 , n , 1);
	memset(f , 0 , sizeof(f));
	for(int i = 1 ; i <= n ; i++ )
		if(a[i] != 1) f[1] = 1;
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 0 ; j < q[i].size() ; j++ ) f[ask(1 , n , q[i][j] , 1)] = 1;
		upd(1 , n , i , nex[i] , a[i] , 1);
	}
	mex = 1;
	while(f[mex]) mex++;
	printf("%d" , mex);
	return 0;
}
/*

*/