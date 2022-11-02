#include<bits/stdc++.h>
using namespace std;
int n , a[1100000] , vis[1100000] , lnk[1100000] , ans[1100000] , sum;
void dfs( int u )
{
	if(vis[u]) return ;
	ans[u] = 1; sum = (sum + u) % (2 * n);
	vis[u] = vis[lnk[u]] = 1;
	dfs((lnk[u] + n - 1) % (2 * n) + 1);
}
int main()
{
	scanf("%d" , &n);
	if(!(n & 1))
	{
		printf("First\n"); fflush(stdout);
		for(int i = 1 ; i <= 2 * n ; i++ ) printf("%d " , (i - 1) % n + 1);
		printf("\n"); fflush(stdout);
		scanf("%d" , &n);
		return 0;
	}
	printf("Second\n"); fflush(stdout);
	for(int i = 1 ; i <= 2 * n ; i++ ) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= 2 * n ; i++ )
	{
		if(vis[a[i]]) lnk[vis[a[i]]] = i , lnk[i] = vis[a[i]] , vis[a[i]] = 0;
		else vis[a[i]] = i;
	}
	for(int i = 1 ; i <= 2 * n ; i++ )
		if(!vis[i]) dfs(i);
	if(sum == n)
	{
		for(int i = 1 ; i <= 2 * n ; i++ ) 
			if(!ans[i]) printf("%d " , i);
	}
	else
	{
		for(int i = 1 ; i <= 2 * n ; i++ ) 
			if(ans[i]) printf("%d " , i);
	}
	printf("\n"); fflush(stdout);
	scanf("%d" , &n);
    return 0;
}
/*

*/