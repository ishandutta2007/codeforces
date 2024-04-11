#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+50;
int n,m,c1,c2,ans=0;
int vis[N];
vector<int> e[N];
void dfs(int x)
{
	c1++;
	vis[x]=1;
	for(int v:e[x])
	{
		c2++;
		if(vis[v]) continue;
		dfs(v);	
	}
}
int main()
{
	int i,u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		c1=c2=0;
		dfs(i);
		c2>>=1;
		ans+=max(c2-(c1-1),0);
	}
	printf("%d",ans);
	return 0;
}