#include <bits/stdc++.h>
using namespace std;
int n , m , s , vis[220000] , x , y , z , in[220000];
int dep[220000] , fa[20][220000] , siz[220000] , ans;
int fst[220000] , nex[660000] , v[660000] , val[660000] , tot;
int fst1[220000] , nex1[660000] , v1[660000];
long long dis[220000];
queue< int > q;
vector< int > sn[220000];
struct item
{
	int id; long long num;
	bool operator < ( const item &x ) const
	{
		return num > x.num;
	}
};
inline void add( int a , int b , int c )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; val[tot] = c;
}
inline void add1( int a , int b )
{
	nex1[++tot] = fst1[a]; fst1[a] = tot;
	v1[tot] = b; in[b]++;
}
inline int lca( int a , int b )
{
	if(!a || !b) return a + b;
	if(dep[a] < dep[b]) swap(a , b);
	for(int i = 18 ; i >= 0 ; i-- )
		if(dep[fa[i][a]] >= dep[b]) a = fa[i][a];
	if(a == b) return a;
	for(int i = 18 ; i >= 0 ; i-- )
		if(fa[i][a] != fa[i][b]) a = fa[i][a] , b = fa[i][b];
	return fa[0][a];
}
void dij()
{
	memset(dis , 0x7f / 3 , sizeof(dis));
	priority_queue< item > q;
	q.push((item){s , 0}); dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(!vis[v[i]] && dis[v[i]] > dis[u] + val[i])
			{
				dis[v[i]] = dis[u] + val[i];
				q.push((item){v[i] , dis[v[i]]});
			}
		}
	}
	return ;
}
void dfs( int u )
{
	siz[u] = 1;
	for(int i = 0 ; i < sn[u].size() ; i++ )
	{
		dfs(sn[u][i]);
		siz[u] += siz[sn[u][i]];
	}
	return ;
}
void build()
{
	int tt = tot;
	tot = 0;
	for(int i = 1 ; i <= tt ; i++ ) 
	{
		int qwq = ((i - 1) ^ 1) + 1;
		if(dis[v[i]] == dis[v[qwq]] + val[i]) add1(v[qwq] , v[i]);
	}
	memcpy(fst , fst1 , sizeof(fst));
	memcpy(v , v1 , sizeof(v));
	memcpy(nex , nex1 , sizeof(nex));
	return ;
}
int main()
{
	scanf("%d%d%d" , &n , &m , &s);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d%d" , &x , &y , &z);
		add(x , y , z); add(y , x , z);
	}
	dij();
	build();
	memset(vis , 0 , sizeof(vis));
	fa[0][s] = s , q.push(s); 
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		dep[u] = dep[fa[0][u]] + 1; vis[u] = 1;
		if(fa[0][u] != u) sn[fa[0][u]].push_back(u);
		for(int i = 1 ; i <= 18 ; i++ ) fa[i][u] = fa[i - 1][fa[i - 1][u]];
		for(int i = fst[u] ; i ; i = nex[i] )
		{
			if(vis[v[i]]) continue;
//			cerr << u << ' ' << v[i] << endl;
			in[v[i]]--; fa[0][v[i]] = lca(fa[0][v[i]] , u);
			if(!in[v[i]]) q.push(v[i]);
		}
	}
	dfs(s);
	for(int i = 1 ; i <= n ; i++ )
		if(i != s) ans = max(ans , siz[i]);
	printf("%d" , ans);
	return 0;
}