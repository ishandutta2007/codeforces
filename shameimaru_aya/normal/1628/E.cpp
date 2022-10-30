#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int n , m , x , y , z , opt , fa[660000] , w[660000] , dfn[660000] , nfd[660000];
int dep[660000] , ffa[20][660000] , tag[1220000];
int fst[330000] , nex[660000] , v[660000] , val[660000] , tot = 1;
vector< int > son[660000];
struct item
{
	int num , id;
	bool operator < ( const item &x ) const
	{
		return num < x.num;
	}
} node[330000];
void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
struct D
{
	int maxx , minn;
	D operator + ( const D &x ) const
	{
		return (D){max(maxx , x.maxx) , min(minn , x.minn)};
	}
} c[1220000] , cw[1220000] , gg , noww;
int getf( int x )
{
	if(fa[x] == x) return x;
	return fa[x] = getf(fa[x]);
}
void dfs( int u , int F )
{
	dfn[u] = ++tot; nfd[tot] = u; dep[u] = dep[F] + 1; ffa[0][u] = F;
	for(int i = 1 ; i <= 19 ; i++ ) ffa[i][u] = ffa[i - 1][ffa[i - 1][u]];
	for(int v : son[u]) dfs(v , u);
}
void build( int l , int r , int id )
{
	tag[id] = -1;
	if(l == r)
	{
		cw[id] = (D){dfn[l] , dfn[l]}; c[id] = gg;
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	cw[id] = cw[lson] + cw[rson]; c[id] = c[lson] + c[rson];
}
void push_down( int id )
{
	if(tag[id] == -1) return ;
	if(tag[id] == 0)
	{
		tag[lson] = tag[rson] = 0;
		c[lson] = c[rson] = gg;
	}
	else
	{
		tag[lson] = tag[rson] = 1;
		c[lson] = cw[lson]; c[rson] = cw[rson];
	}
	tag[id] = -1;
}
void upd( int l , int r , int a , int b , int d , int id )
{
	if(b < l || r < a) return ;
	if(a <= l && r <= b)
	{
		if(d) c[id] = cw[id];
		else c[id] = gg;
		tag[id] = d;
		return ;
	}
	push_down(id);
	int mid = l + r >> 1;
	upd(l , mid , a , b , d , lson); upd(mid + 1 , r , a , b , d , rson);
	c[id] = c[lson] + c[rson];
}
int lca( int a , int b )
{
	a = nfd[a]; b = nfd[b]; 
	if(dep[a] < dep[b]) swap(a , b);
	for(int i = 19 ; i >= 0 ; i-- ) 
		if(dep[ffa[i][a]] >= dep[b]) a = ffa[i][a];
	if(a == b) return a;
	for(int i = 19 ; i >= 0 ; i-- ) 
		if(ffa[i][a] != ffa[i][b]) a = ffa[i][a] , b = ffa[i][b];
	return ffa[0][a];
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	gg = (D){-(int)1e9 , (int)1e9};
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i < n ; i++ )
	{
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y); add(y , x); node[i] = (item){z , tot};
	}
	sort(node + 1 , node + n); tot = n;
	for(int i = 1 ; i <= n ; i++ ) fa[i] = i , w[i] = -1;
	for(int i = 1 ; i < n ; i++ )
	{
		++tot; fa[tot] = tot; w[tot] = node[i].num;
		int x = v[node[i].id] , y = v[node[i].id ^ 1];
		son[tot].push_back(getf(x)); son[tot].push_back(getf(y));
		fa[getf(x)] = tot; fa[getf(y)] = tot; 
	}
	int qwq = tot; tot = 0; dfs(qwq , qwq); 
	build(1 , n , 1);
	while(m--)
	{
		scanf("%d" , &opt);
		if(opt == 1)
		{
			scanf("%d%d" , &x , &y); upd(1 , n , x , y , 1 , 1);
		}
		if(opt == 2)
		{
			scanf("%d%d" , &x , &y); upd(1 , n , x , y , 0 , 1);
		}
		if(opt == 3)
		{
			scanf("%d" , &x); noww = c[1] + (D){dfn[x] , dfn[x]}; 
			printf("%d\n" , w[lca(noww.minn , noww.maxx)]);
		}
	}
	return 0;
}
/*

*/