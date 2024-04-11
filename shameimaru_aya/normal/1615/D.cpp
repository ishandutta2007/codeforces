#include <bits/stdc++.h>
using namespace std;
int T , n , m , x , y , z , dfn[1660000] , low[1660000] , vis[1660000] , scc[1660000];
int fst[1660000] , nex[1660000] , v[1660000] , tot , cnt , gg;
int d[1660000] , s[1660000];
stack< int > st;
vector< int > son[1660000] , w[1660000] , f[1660000];
void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; 
}
void addt( int a , int b , int c )
{
	son[a].push_back(b); w[a].push_back(c); f[a].push_back(0);
}
void tarjan( int u )
{
	vis[u] = 1; st.push(u);
	dfn[u] = low[u] = ++tot;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(!dfn[v[i]])
		{
			tarjan(v[i]);
			low[u] = min(low[u] , low[v[i]]);
		}
		else if(vis[v[i]]) low[u] = min(low[u] , dfn[v[i]]);
	}
	if(dfn[u] == low[u])
	{
		++cnt;
		while(!st.empty())
		{
			int noww = st.top(); st.pop();
			scc[noww] = cnt; vis[noww] = 0;
			if(noww == u) break;
		}
	}
}
void dfs1( int u , int fa )
{
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		int v = son[u][i] , val = w[u][i]; 
		if(v == fa) continue; f[u][i] = 1;
		if(~val) 
		{
			d[v] = d[u] ^ val;
			add(u , v) , add(u + n , v + n);
			add(v , u) , add(v + n , u + n);
		}
		else d[v] = d[u];
		dfs1(v , u);
	}
}
void dfs2( int u , int fa )
{
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		int v = son[u][i] , val = w[u][i];
		if(v == fa) continue;
		if(val == -1)
		{
			if(s[u] != s[v]) w[u][i] = 1;
			else w[u][i] = 0;
		}
		dfs2(v , u);
	}
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m); gg = 0;
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d%d" , &x , &y , &z);
			addt(x , y , z); addt(y , x , z);
		}
		dfs1(1 , 1);
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d%d" , &x , &y , &z);
			if(__builtin_popcount(d[x] ^ d[y]) % 2 == z) 
			{
				add(x , y); add(x + n , y + n); 
				add(y , x); add(y + n , x + n); 
			}
			else
			{
				add(x , y + n); add(x + n , y); 
				add(y , x + n); add(y + n , x); 
			}
		}
		tot = 0;
		for(int i = 1 ; i <= 2 * n ; i++ ) 
			if(!dfn[i]) tarjan(i);
		for(int i = 1 ; i <= n ; i++ )
		{
			if(scc[i] == scc[i + n])
			{
				printf("NO\n"); gg = 1;
				break;
			}
		}
		if(!gg) 
		{
			for(int i = 1 ; i <= n ; i++ )
			{
				if(scc[i + n] < scc[i]) s[i] = 1;
				else s[i] = 0;
			}
			dfs2(1 , 1);
			printf("YES\n");
			for(int i = 1 ; i <= n ; i++ )
			{
				for(int j = 0 ; j < son[i].size() ; j++ )
				{
					if(!f[i][j]) continue;
					printf("%d %d %d\n" , i , son[i][j] , w[i][j]);
				}
			}
		}
		for(int i = 1 ; i <= 2 * n ; i++ ) 
			fst[i] = dfn[i] = 0 , son[i].clear() , w[i].clear() , f[i].clear();
		tot = 0;
	}
	
	return 0;
}