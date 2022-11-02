#include<bits/stdc++.h>
using namespace std;
int T , n , m , maxx , x , y , pl , A[550000] , B[550000] , cnt , fa[550000] , dep[550000];
int fst[550000] , nex[2200000] , v[2200000] , tot;
vector< int > sn[550000] , id[550000];
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void dfs( int u )
{
	maxx = max(maxx , dep[u]);
	if(dep[u] == maxx) pl = u; 
	id[dep[u]].push_back(u);
	for(int i = fst[u] ; i ; i = nex[i] )
	{
		if(dep[v[i]]) continue;
		dep[v[i]] = dep[u] + 1; sn[u].push_back(v[i]); fa[v[i]] = u;
		dfs(v[i]);
	}
	return ;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= m ; i++ )
		{
			scanf("%d%d" , &x , &y);
			add(x , y); add(y , x);
		}
		dep[1] = 1; dfs(1);
		if(maxx >= (n + 1) / 2) 
		{
			printf("PATH\n%d\n" , maxx);
			while(pl != 1)
			{
				printf("%d " , pl);
				pl = fa[pl];
			}
			printf("1\n");
			for(int i = 1 ; i <= n ; i++ )
				sn[i].clear() , id[i].clear() , fst[i] = dep[i] = 0;
			tot = maxx = 0;
			continue;
		}
		printf("PAIRING\n");
		for(int i = 1 ; i <= maxx ; i++ )
		{
			for(int j = 1 ; j < id[i].size() ; j += 2 )
				A[++cnt] = id[i][j] , B[cnt] = id[i][j - 1];
		}
		printf("%d\n" , cnt);
		for(int i = 1 ; i <= cnt ; i++ ) printf("%d %d\n" , A[i] , B[i]);
		for(int i = 1 ; i <= n ; i++ )
			sn[i].clear() , id[i].clear() , fst[i] = dep[i] = 0;
		tot = maxx = cnt = 0;
	}
    return 0;
}
/*
*/