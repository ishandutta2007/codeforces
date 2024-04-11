#include <bits/stdc++.h>
using namespace std;
int n , x[550000] , y[550000] , xx[550000] , yy[550000] , ans , dfa[550000] , rt[550000];
int du[550000] , f[550000] , dep[550000] , fa[550000] , dep2[550000] , fa2[550000] , t[4][550000];
pair< int , int > e[550000];
vector< int > son[550000];
map< pair< int , int > , int > mp;
queue< int > q;
void dfs( int u , int F )
{
	fa[u] = F; dep[u] = dep[F] + 1;
	for(int v : son[u])
	{
		if(v == F) continue;
		dfs(v , u);
	}
}
void dfs2( int u , int F )
{
	fa2[u] = F; dep2[u] = dep2[F] + 1;
	for(int v : son[u])
	{
		if(v == F) continue;
		dfs2(v , u);
	}
}
int getf( int x )
{
	if(x == dfa[x]) return x;
	return dfa[x] = getf(dfa[x]);
}
void merge( int x , int y )
{
	int a = getf(x) , b = getf(y);
	if(a == b) return ;
	dfa[b] = a; 
	if(getf(fa2[rt[a]]) == a) rt[a] = rt[b];
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) dfa[i] = rt[i] = i;
	for(int i = 1 ; i < n ; i++ ) scanf("%d%d" , &xx[i] , &yy[i]); 
	for(int i = 1 ; i < n ; i++ ) scanf("%d%d" , &x[i] , &y[i]); 
	for(int i = 1 ; i < n ; i++ )
	{
		son[x[i]].push_back(y[i]); son[y[i]].push_back(x[i]); 
		mp[{x[i] , y[i]}] = 1;
	}
	dfs(1 , 1); 
	for(int i = 1 ; i <= n ; i++ ) son[i].clear();
	for(int i = 1 ; i < n ; i++ )
		son[xx[i]].push_back(yy[i]) , son[yy[i]].push_back(xx[i]); 
	dfs2(1 , 1);
	for(int i = 1 ; i < n ; i++ )
	{
		if(mp[{xx[i] , yy[i]}] || mp[{yy[i] , xx[i]}]) 
		{
			if(dep[xx[i]] < dep[yy[i]]) merge(xx[i] , yy[i]);
			else merge(yy[i] , xx[i]);
		}
	}
	for(int i = 1 ; i < n ; i++ )
		if(!mp[{xx[i] , yy[i]}] && !mp[{yy[i] , xx[i]}]) du[getf(xx[i])]++ , du[getf(yy[i])]++;
//	for(int i = 1 ; i <= n ; i++ ) cerr << getf(i) << ' '; cerr << endl;
	for(int i = 1 ; i <= n ; i++ )
	{
		int x = getf(i);
		if(du[x] == 1 && x != 1 && !f[x]) q.push(x);
	}
	while(!q.empty())
	{
		int u = q.front() , v = 114514; q.pop(); 
		if(f[u]) continue;
		f[u] = 1;
//		cerr << rt[u] << ' ' << fa[rt[u]] << endl;
		t[0][++ans] = rt[u]; t[1][ans] = fa2[rt[u]]; t[2][ans] = u; t[3][ans] = fa[u]; 
		v = getf(fa2[rt[u]]);
//		cerr << u << ' ' << v << endl;
		merge(fa[u] , u);
		du[v]--;
		if(du[v] == 1 && v != 1) q.push(v);
	}
	printf("%d\n" , ans);
	for(int i = 1 ; i <= ans ; i++ ) 
		printf("%d %d %d %d\n" , t[0][i] , t[1][i] , t[2][i] , t[3][i]);
	return 0;
}
/*
*/