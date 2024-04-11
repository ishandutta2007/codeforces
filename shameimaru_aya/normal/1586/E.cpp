#include <bits/stdc++.h>
using namespace std;
int n , m , q , x , y , s[330000] , t[330000] , f[330000] , tot , fa[330000] , vis[330000] , dep[330000] , id[330000];
vector< int > son[330000];
void dfs( int u , int F )
{
	if(vis[u]) return ;
	fa[u] = F; dep[u] = dep[F] + 1; vis[u] = 1;
	for(int i = 0 ; i < son[u].size() ; i++ )
	{
		int v = son[u][i];
		if(v == F) continue;
		dfs(v , u);
	}
}
int lca( int x , int y )
{
	if(dep[x] < dep[y]) swap(x , y);
	while(dep[x] != dep[y]) x = fa[x];
	if(x == y) return x;
	while(x != y) x = fa[x] , y = fa[y];
	return x;
}
void climb( int x , int y )
{
	int L = lca(x , y); tot = 0;
//	cerr << x << ' ' << y << ' ' << L << endl;
	while(x != L) id[++tot] = x , x = fa[x]; id[++tot] = L;
	int qwq = tot;
	while(y != L) id[++tot] = y , y = fa[y];
	reverse(id + qwq + 1 , id + tot + 1);
}
int main()
{
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= m ; i++ )
	{
		scanf("%d%d" , &x , &y); 
		son[x].push_back(y); son[y].push_back(x);
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; i++ )
	{
		scanf("%d%d" , &s[i] , &t[i]);
		f[s[i]]++; f[t[i]]++;
	}
	for(int i = 1 ; i <= n ; i++ )
	{
		tot += f[i] & 1;
	}
	if(tot)
	{
		printf("NO\n%d\n" , tot / 2);
		return 0;
	}
	printf("YES\n");
	dfs(1 , 1);
	for(int i = 1 ; i <= q ; i++ )
	{
		climb(s[i] , t[i]);
		printf("%d\n" , tot);
		for(int j = 1 ; j <= tot ; j++ ) printf("%d " , id[j]); printf("\n");
	}
	return 0;
}
/*

*/