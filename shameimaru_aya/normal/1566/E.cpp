#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
int T , n , x , y , bud[220000] , rt[220000] , cnt , du[220000] , t0[220000] , t1[220000];
int id[220000] , ans , dep[220000] , fa[220000] , minn;
int fst[220000] , nex[440000] , v[440000] , tot = 1;
vector< int > son[220000] , val[220000];
bool cmp( int a , int b )
{
	return dep[a] > dep[b];
}
void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void dfs1( int u , int F )
{
	dep[u] = dep[F] + 1; fa[u] = F;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == F) continue;
		dfs1(v[i] , u); du[u]++;
	}
	if(!du[u]) ans++;
}
void dfs2( int u )
{
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		int v = son[u][i];
		dep[v] = dep[u] + val[u][i];
		dfs2(v);
	}
	if(u) minn = min(minn , dep[u]);
}
int main()
{
//	freopen("1.in" , "r" , stdin);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); tot = 1; cnt = 0; ans = 0; minn = 1e9; 
		for(int i = 0 ; i <= n ; i++ ) fst[i] = 0 , son[i].clear() , id[i] = i , du[i] = 0;
		for(int i = 0 ; i <= n ; i++ ) val[i].clear() , t0[i] = t1[i] = 0 , bud[i] = 0;
		for(int i = 1 ; i < n ; i++ ) scanf("%d%d" , &x , &y) , add(x , y) , add(y , x);
		dep[1] = 0; dfs1(1 , 1); sort(id + 1 , id + n + 1 , cmp);
		for(int i = 1 ; i <= n ; i++ )
		{
			int u = id[i];
			if(!du[u]) 
			{
				if(fa[u] == u) continue;
				if(!bud[fa[u]]) bud[fa[u]] = ++cnt , rt[cnt] = fa[u];
				bud[u] = bud[fa[u]];
			}
			else du[fa[u]]--;
		}
//		for(int i = 1 ; i <= n ; i++ ) cerr << bud[i] << ' '; cerr << endl;
		
		for(int i = 2 ; i <= tot ; i++ )
		{
			x = v[i ^ 1] , y = v[i];
			if(dep[x] > dep[y] || bud[x] == bud[y]) continue;
			son[bud[x]].push_back(bud[y]);
			if(x == rt[bud[x]]) t1[x]++ , ans-- , val[bud[x]].push_back(1);
			else t0[x]++ , ans -= (t0[x] != 1) , val[bud[x]].push_back(0);
		}
		dep[bud[1]] = 0; dfs2(bud[1]);
		ans += minn;
		printf("%d\n" , ans);
//		cerr << minn << ' ' << cnt;
	}
	return 0;  
}
/*


*/