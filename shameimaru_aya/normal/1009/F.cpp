#include<bits/stdc++.h>
#define N 1100000
using namespace std;
int n , a[N] , dep[N] , low[N] , hson[N] , dfn[N] , ans[N] , x , y;
int fst[N] , nex[N * 2] , v[N * 2] , tot;
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; 
}
void dfs1( int u , int fa )
{
	dep[u] = dep[fa] + 1;
	low[u] = 0;
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa) continue;
		dfs1(v[i] , u);
		if(low[v[i]] + 1 > low[u]) low[u] = low[v[i]] + 1 , hson[u] = v[i];
	}
	return ;
}
void dfs2( int u , int fa )
{
	dfn[u] = ++tot;
	if(hson[u]) dfs2(hson[u] , u);
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa || v[i] == hson[u]) continue;
		dfs2(v[i] , u);
	}
	return ;
}
void dfs3( int u , int fa )
{
	a[dfn[u]] = 1; ans[u] = 0;
	int maxx = 1;
	if(hson[u])
	{
		dfs3(hson[u] , u);
		if(a[dfn[u] + ans[hson[u]] + 1] > 1)
			ans[u] = ans[hson[u]] + 1 , maxx = a[dfn[u] + ans[hson[u]] + 1];
	}
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(v[i] == fa || v[i] == hson[u]) continue;
		dfs3(v[i] , u);
		for(int j = 0 ; j <= low[v[i]] ; j++ )
		{
			a[dfn[u] + j + 1] += a[dfn[v[i]] + j];
			if(a[dfn[u] + j + 1] > maxx || (a[dfn[u] + j + 1] == maxx && ans[u] > j + 1))
				maxx = a[dfn[u] + j + 1] , ans[u] = j + 1;
		}
	}
	return ;
}
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i < n ; i++ )
	{
		scanf("%d%d" , &x , &y);
		add(x , y); add(y , x);
	}
	tot = 0;
	dfs1(1 , 1);
	dfs2(1 , 1);
	dfs3(1 , 1);
	for(int i = 1 ; i <= n ; i++ ) printf("%d\n" , ans[i]);
	return 0;
}