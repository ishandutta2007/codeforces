#include<bits/stdc++.h>
#define MAXN 300005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
int ans[MAXN];
int dep[MAXN];
vector<int> G[MAXN];
int n,q,tot;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
int pa[MAXLOGN][MAXN];

int depth[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p; 
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
vector<int> add[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		init(n);
		int v=1;
		for(int i=1;i<=n;i++) if(depth[i]>depth[v]) v=i;
		for(int i=1;i<=n;i++) ans[i]=depth[v];
		for(int i=0;i<=n;i++) add[i].clear();
		for(int i=2;i<=n;i++) add[depth[i]-1].push_back(i);
		int d=0;
		for(int i=depth[v]-1;i>=1;i--)
		{
			for(auto x:add[i]) d=max(d,dis(x,v));
			int val=(d+1)/2;
			int need=i-val;
			if(need>=1) ans[need]=i; else break;	
		}
		for(int i=n-1;i>=1;i--) ans[i]=min(ans[i],ans[i+1]);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}