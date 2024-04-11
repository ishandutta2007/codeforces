#include <bits/stdc++.h>
using namespace std;
int T , n , x , y , d[110000];
vector< int > son[110000];
void dfs( int u , int fa )
{
	for(int v : son[u])
	{
		if(fa == v) continue;
		if(d[u] > 0) d[v] = -d[v];
		dfs(v , u);
	}
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ ) d[i] = 0 , son[i].clear();
		for(int i = 1 ; i < n ; i++ )
		{
			scanf("%d%d" , &x , &y); d[x]++; d[y]++;
			son[x].push_back(y); son[y].push_back(x); 
		}
		dfs(1 , 1);
		for(int i = 1 ; i <= n ; i++ ) printf("%d " , d[i]); printf("\n");
	}
	return 0;
}
/*
*/