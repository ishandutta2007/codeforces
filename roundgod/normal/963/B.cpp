#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,k,a[MAXN],deg[MAXN];
vector<int> G[MAXN];
int dp[MAXN];
void dfs(int v,int p)
{
	int cnt=0;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
		if(dp[G[v][i]]==-1) cnt++; 
	}
	if(cnt&1) dp[v]=1; else dp[v]=-1; 
}
void solve(int v,int p)
{
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		if(dp[G[v][i]]==1) solve(G[v][i],v);
	}
	printf("%d\n",v);
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		if(dp[G[v][i]]==-1) solve(G[v][i],v);
	}
}
int main()
{
	scanf("%d",&n);
	int root;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x!=0) {G[x].push_back(i); G[i].push_back(x);}
		if(x==0) root=i;
	}
	memset(dp,0,sizeof(dp));
	dfs(root,-1);
	if(dp[root]==1) {puts("NO"); return 0;}
	puts("YES");
	solve(root,-1);
	return 0;
}