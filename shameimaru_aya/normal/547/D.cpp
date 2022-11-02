#include <bits/stdc++.h>
using namespace std;
int n , x , y , du[880000] , s , vis[880000] , flag , ans[220000];
int fst[880000] , nex[1880000] , v[1880000] , dir[1880000] , id[1880000] , cur[880000] , tot = 1;
const int N = 2e5;
void add( int a , int b , int c = 0 )
{
	nex[++tot] = fst[a]; fst[a] = tot;
	v[tot] = b; id[tot] = c;
}
void dfs( int u )
{
	for( ; cur[u] ; cur[u] = nex[cur[u]] )
	{
		int i = cur[u];
		if(dir[i]) continue;
		dir[i] = 1; dir[i ^ 1] = -1; 
		dfs(v[i]);
	}
	return ;
}
int main()
{
//	freopen("1.in" , "r" , stdin);
//	freopen("1.out" , "w" , stdout);
	scanf("%d" , &n); s = 0;
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%d%d" , &x , &y);
		add(x , y + N , i); add(y + N , x , i);
		du[x]++; du[y + N]++;
	}
	for(int i = 1 ; i <= 2 * N ; i++ ) 
		if(du[i] & 1) add(s , i) , add(i , s);
	memcpy(cur , fst , sizeof(cur));
	for(int i = 1 ; i <= 2 * N ; i++ ) 
		if(!vis[i]) dfs(i);
	for(int i = 1 ; i <= N ; i++ )
		for(int j = fst[i] ; j ; j = nex[j] ) ans[id[j]] = dir[j];
	for(int i = 1 ; i <= n ; i++ ) 
		printf(ans[i] == 1 ? "b" : "r");
	return 0;
}
/*

*/