#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,dep[MAXN],dist[MAXN],color[MAXN],pos[MAXN];
vector<int> G[MAXN];
int fa[MAXN],mx[MAXN];
void dfs(int v,int p,int d)
{
	dep[v]=d; fa[v]=p;
	for(auto to:G[v])
	{
		if(to==p) continue;
		dfs(to,v,d+1);
	}
}
void dfs2(int v,int p,int d)
{
	dist[v]=mx[v]=d;
    for(auto to:G[v])
	{
		if(to==p) continue;
		dfs2(to,v,d+1);
		mx[v]=max(mx[v],mx[to]);
	}	
}
void dfs3(int v,int p,int c,int dir)
{
	c+=dir;
	if(c<0) c=k-1; 
	if(c>k) c=1;
	color[v]=c;
	for(auto to:G[v])
	{
		if(to==p) continue;
		dfs3(to,v,c,dir);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	memset(dist,0,sizeof(dist));
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v); G[v].push_back(u);
	}
	dfs(1,0,0);
	if(k==2)
	{
		puts("Yes");
		for(int i=1;i<=n;i++) printf("%d%c",dep[i]&1?1:2,i==n?'\n':' ');
		return 0;
	}
	int u=1;
	for(int i=1;i<=n;i++) if(dep[i]>dep[u]) u=i;
	dfs(u,0,0);
	int root=u,diam=0;
	for(int i=1;i<=n;i++)
	{
		if(dep[i]>dep[u]) u=i;
	}
	diam=dep[u];
	if(diam<k-1)
	{
		puts("Yes");
		for(int i=1;i<=n;i++) printf("%d%c",1,i==n?'\n':' ');
	    return 0;	
	}
	int cur=1,cnt=1;
	while(u)
	{
		dist[u]=-1;
		color[u]=cur;
		pos[u]=cnt;
		cur++; cnt++; if(cur>k) cur=1;
		u=fa[u];
	};
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		if(dist[i]==-1)
		{
			int x=pos[i]-1,y=diam-x;
			for(auto to:G[i])
			{
				if(dist[to]==-1) continue;
				dfs2(to,i,1);
				if(mx[to]+x>=k-1&&mx[to]+y>=k-1) f=false;
				else if(mx[to]+x>=k-1) dfs3(to,i,color[i],1); else dfs3(to,i,color[i],-1);
			}	
		}
	}
	if(!f) {puts("No"); return 0;}
	puts("Yes");
	for(int i=1;i<=n;i++) printf("%d%c",color[i],i==n?'\n':' '); 
	return 0;
}