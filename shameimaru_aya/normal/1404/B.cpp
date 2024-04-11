#include<bits/stdc++.h>
using namespace std;
int T , n , a , b , da , db , x , y , maxd , id , dep[110000] , fa[25][110000];
int fst[110000] , nex[220000] , v[220000] , tot , f;
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
	return ;
}
void dfs( int u , int f )
{
	dep[u] = dep[f] + 1;
	fa[0][u] = f;
	for(int i = 1 ; i <= 23 ; i++ ) fa[i][u] = fa[i - 1][fa[i - 1][u]];
	if(dep[u] > maxd) maxd = dep[u] , id = u;
	for(int i = fst[u] ; i ; i = nex[i])
	{
		if(v[i] == f) continue;
		dfs(v[i] , u);
	}
	return ;
}
inline int lca( int x , int y )
{
	if(dep[x] < dep[y]) swap(x , y);
	for(int i = 23 ; i >= 0 ; i-- )
	{
		if(dep[fa[i][x]] >= dep[y])
		{
			x = fa[i][x];
			if(x == y) return x;
		}
	}
	for(int i = 23 ; i >= 0 ; i-- )
	{
		if(fa[i][x] != fa[i][y])
		{
			x = fa[i][x];
			y = fa[i][y];
		}
	}
	return fa[0][x];
}
inline int dis( int a , int b )
{
	return dep[a] + dep[b] - (dep[lca(a , b)] << 1);
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		tot = maxd = f = 0;
		scanf("%d%d%d%d%d" , &n , &a , &b , &da , &db);
		for(int i = 1 ; i <= n ; i++ ) fst[i] = 0;
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d" , &x , &y);
			add(x , y); add(y , x);
		}
		if(da * 2 >= db)
		{
			printf("Alice\n");
			continue;
		}
		dep[1] = 0;
		dfs(1 , 1);
		if(dis(a , b) <= da) 
		{
//			cerr << dep[6] << ' ' << dep[1] << ' ' << lca(1 , 6) << endl;
			printf("Alice\n");
			continue;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			if(dis(id , i) > 2 * da)
			{
				printf("Bob\n");
				f = 1;
				break;
			}
		}
		if(!f) printf("Alice\n");
	}
    return 0;
}