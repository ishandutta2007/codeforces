#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,m,s;
vector<int> G[MAXN];
vector<int> G2[MAXN];
bool deg[MAXN],reach[MAXN];
int pre[MAXN],color[MAXN];
bool f;
void dfs(int p,int v)
{
	pre[v]=p;
	reach[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		if(!reach[G[v][i]]) dfs(v,G[v][i]);
	}
}
void dfs2(int v)
{
	color[v]=1;
	for(int i=0;i<G2[v].size();i++)
	{
		int to=G2[v][i];
		if(color[to]==0) dfs2(to);
		if(color[to]==1) f=false;
	}
	color[v]=2;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(deg,false,sizeof(deg));
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		if(num!=0) deg[i]=true;
		for(int j=0;j<num;j++)
		{
			int x;
			scanf("%d",&x);x--;
			G[i].push_back(n+x);
			G[n+i].push_back(x);
			G2[i].push_back(x);
		}
	}
	memset(reach,false,sizeof(reach));
	memset(pre,0,sizeof(pre));
	scanf("%d",&s);
	s--;
	dfs(-1,s);
	for(int i=0;i<n;i++)
		if(!deg[i]&&reach[n+i])
		{
			puts("Win");
			vector<int> ans;
			int now=n+i;
			while(now!=-1)
			{
				ans.push_back(now);
				now=pre[now];
			}
			for(int j=ans.size()-1;j>=0;j--)
				printf("%d ",ans[j]>=n?ans[j]-n+1:ans[j]+1);
			return 0;
		}
	memset(color,0,sizeof(color));
	f=true;
	dfs2(s);
	if(f) puts("Lose"); else puts("Draw");
	return 0;
}