#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int n , m , x , y , f[220000] , d[220000] , b , cnt , lazy[880000];
int fa[220000] , dfn[220000] , dfo[220000] , nfd[220000];
int fst[1660000] , nex[1660000] , v[1660000] , tot;
long long ans = -1e18;
struct item
{
	int num , id;
	bool operator < ( const item &x ) const
	{
		if(num < x.num) return 1;
		return 0;
	}
	bool operator > ( const item &x ) const
	{
		if(num > x.num) return 1;
		return 0;
	}
} c[880000];
void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; 
}
void dfs( int u , int F )
{
	d[u] = d[F] + 1; fa[u] = F; dfn[u] = ++cnt; nfd[cnt] = u;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == F) continue;
		dfs(v[i] , u);
	}
	dfo[u] = cnt; 
}
void build( int l , int r , int id )
{
	if(l == r)
	{
		c[id] = (item){d[nfd[l]] , nfd[l]};
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	c[id] = max(c[lson] , c[rson]);
}
void push_down( int id )
{
	if(lazy[id] == 0) return ;
	lazy[lson] += lazy[id]; lazy[rson] += lazy[id]; 
	c[lson].num += lazy[id]; c[rson].num += lazy[id]; 
	lazy[id] = 0;
}
void upd( int l , int r , int a , int b , int d , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		lazy[id] -= d; c[id].num -= d;
		return ;
	}
	push_down(id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , d , lson); upd(mid + 1 , r , a , b , d , rson);
	c[id] = max(c[lson] , c[rson]);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i < n ; i++ ) scanf("%d%d" , &x , &y) , add(x , y) , add(y , x);
	dfs(1 , 0);
	build(1 , n , 1); b = n;
	for(int i = 1 ; i <= m ; i++ )
	{
		int u = c[1].id;
//		cerr << u << ' ' << c[1].num << endl;
		while(!f[u] && u)
		{
//			cerr << dfn[u] << ' ' << dfo[u] << endl;
			upd(1 , n , dfn[u] , dfo[u] , 1 , 1);
			f[u] = 1; u = fa[u]; b--;
		}
//		cerr << i << ' ' << b << ' ' << u << endl;
		if(b >= n / 2) ans = max(ans , 1ll * (n - i) * i - 1ll * n / 2 * (n - n / 2));
		else ans = max(ans , 1ll * (n - i) * i - 1ll * b * (n - b));
	}
	printf("%lld" , ans);
	return 0;
}