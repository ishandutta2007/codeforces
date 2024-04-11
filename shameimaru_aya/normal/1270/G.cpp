#include<bits/stdc++.h>
using namespace std;
int T , n , a , vis[1100000] , cc , ans[1100000] , cnt;
int fst[1100000] , nex[2200000] , v[2200000] , tot;
inline void add( int a , int b )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b;
}
void dfs( int u )
{
	vis[u] = 1;
	for(int i = fst[u] ; ~i ; i = nex[i] )
	{
		if(vis[v[i]])
		{
			cc = v[i];
			ans[++cnt] = u;
			if(cc == u) cc = -1;
			return ;
		}
		dfs(v[i]);
		if(cc && ~cc) ans[++cnt] = u;
		if(cc == u) cc = -1;
		if(cc) return ;
	}
}
int main()
{
//	freopen("1.in" , "r" , stdin);
	memset(fst , -1 , sizeof(fst));
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a);
			add(i , i - a); 
		}
		for(int i = 1 ; i <= n && !cc ; i++ )
			if(!vis[i]) dfs(i);
		printf("%d\n" , cnt);
		for(int i = cnt ; i >= 1 ; i-- ) printf("%d " , ans[i]);
		printf("\n");
		for(int i = 1 ; i <= n ; i++ ) fst[i] = -1 , vis[i] = 0;
		tot = -1 , cc = cnt = 0;
	}
    return 0;
}
/*
*/