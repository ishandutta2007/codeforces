#include<bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
int n , m , qq , N , a[220000] , opt , x , y , fa[220000] , cnt;
int c[880000] , dfn[220000] , nfd[220000] , low[220000];
int siz[220000] , hson[220000] , dep[220000] , top[220000];
int fst[220000] , nex[880000] , v[880000] , tot;
vector< int > in[110000];
stack< int > s;
priority_queue< int , vector< int > , greater< int > > q[220000] , del[220000];
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
inline int read_opt()
{
	char c = getchar();
	while(c != 'A' && c != 'C') c = getchar();
	if(c == 'A') return 1;
	return 2;
}
void tarjan( int u , int fa )
{
	dfn[u] = low[u] = ++tot; s.push(u);
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		if(!dfn[v[i]]) 
		{
			tarjan(v[i] , u);
			low[u] = min(low[u] , low[v[i]]);
			if(low[v[i]] >= dfn[u])
			{
				cnt++;
				int qwq;
				do
				{
					qwq = s.top(); s.pop();
					in[qwq].push_back(cnt);
				} while(qwq != v[i]);
				in[u].push_back(cnt);
			}
		}
		else low[u] = min(low[u] , dfn[v[i]]);
	}
}
void build( int l , int r , int id )
{
	if(l == r)
	{
		c[id] = a[nfd[l]];
		return ;
	}
	int mid = l + r >> 1;
	build(l , mid , lson); build(mid + 1 , r , rson);
	c[id] = min(c[lson] , c[rson]);
	return ;
}
void upd( int l , int r , int a , int b , int id )
{
	if(r < a || a < l) return ;
	if(l == r)
	{
		c[id] = b;
		return ;
	}
	int mid = l + r >> 1;
	upd(l , mid , a , b , lson); upd(mid + 1 , r , a , b , rson);
	c[id] = min(c[lson] , c[rson]);
	return ;
}
int ask( int l , int r , int a , int b , int id )
{
	if(r < a || b < l) return 1e9;
	if(a <= l && r <= b) return c[id];
	int mid = l + r >> 1;
	return min(ask(l , mid , a , b , lson) , ask(mid + 1 , r , a , b , rson));
}
void dfs1( int u , int f )
{
	fa[u] = f;
	if(fa[u] > n) q[fa[u]].push(a[u]);
	siz[u] = 1; dep[u] = dep[f] + 1;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == f) continue;
		dfs1(v[i] , u);
		siz[u] += siz[v[i]];
		if(siz[v[i]] > siz[hson[u]]) hson[u] = v[i];
	}
	return ;
}
void dfs2( int u , int t )
{
	dfn[u] = ++tot; nfd[tot] = u; top[u] = t;
	if(hson[u]) dfs2(hson[u] , t);
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa[u] || v[i] == hson[u]) continue;
		dfs2(v[i] , v[i]); 
	}
	return ;
}
int climb( int x , int y )
{
	int fx = top[x] , fy = top[y] , ans = 1e9;
	while(fx != fy)
	{
		if(dep[fx] > dep[fy])
		{
			ans = min(ans , ask(1 , N , dfn[fx] , dfn[x] , 1));
			x = fa[fx]; fx = top[x];
		}
		else
		{
			ans = min(ans , ask(1 , N , dfn[fy] , dfn[y] , 1));
			y = fa[fy]; fy = top[y];
		}
	}
	if(dep[x] < dep[y]) ans = min(ans , ask(1 , N , dfn[x] , dfn[y] , 1)) , y = x;
	else ans = min(ans , ask(1 , N , dfn[y] , dfn[x] , 1)) , x = y;
	if(x > n) ans = min(ans , a[fa[x]]);
	return ans;
}
int main()
{
	scanf("%d%d%d" , &n , &m , &qq);
	for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= m ; i++ ) 
	{
		scanf("%d%d" , &x , &y);
		add(x , y); add(y , x);
	}
	tot = 0;
	tarjan(1 , 1);
	memset(fst , 0 , sizeof(fst)); tot = 0;
	for(int u = 1 ; u <= n ; u++ )
		for(int i = 0 ; i < in[u].size() ; i++ ) 
			add(u , n + in[u][i]) , add(n + in[u][i] , u);
	N = n + cnt;
	tot = 0;
	dfs1(1 , 1); dfs2(1 , 1);
	for(int i = n + 1 ; i <= N ; i++ ) a[i] = q[i].top();
	build(1 , N , 1);
	while(qq--)
	{
		opt = read_opt(); scanf("%d%d" , &x , &y);
		if(opt == 1) printf("%d\n" , climb(x , y));
		else
		{
			del[fa[x]].push(a[x]); a[x] = y; q[fa[x]].push(y); 
			while(del[fa[x]].size() && q[fa[x]].size())
			{
				if(del[fa[x]].top() == q[fa[x]].top()) del[fa[x]].pop() , q[fa[x]].pop();
				else break;
			}
			if(fa[x] > n) a[fa[x]] = q[fa[x]].top();
			upd(1 , N , dfn[x] , y , 1); upd(1 , N , dfn[fa[x]] , a[fa[x]] , 1); 
		}
	}
	return 0;
}
/*
6 7 5
4
2
1
9
7
6
2 1
1 3
2 3
1 4
5 1
4 5
4 6
C 6 2
A 5 4
A 5 6
A 4 1
C 1 5
*/