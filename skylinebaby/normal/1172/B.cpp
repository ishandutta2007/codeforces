#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
//vector <int> adj[212345];
int deg[212345];
//long long dp[212345];
//int vis[212345];
long long lad[212345];
/*void dfs(int x)
{
	vis[x] = 1;
	for(int i = 0;i<adj[x].size();i++)
	{		
		int y = adj[x][i];
		if(vis[y]) continue;
		dp[x] = (dp[x]*dp[y])%N;
	}
}*/
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		//vis[i] = 0;
		deg[i] = 0;
	}
	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		//adj[x].push_back(y);
		//adj[y].push_back(x);
		deg[x-1] ++;
		deg[y-1] ++;
	}
	lad[0] = 1;
	for(int i = 1;i<n;i++) lad[i] = (lad[i-1]*i)%N;
	long long ans = n;
	for(int i = 0;i<n;i++)
	{
		ans = (ans*lad[deg[i]])%N;
	} 
	printf("%lld\n",ans%N);
}