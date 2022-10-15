#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int root,n,k,fa[MAXN],x[MAXN],y[MAXN];
vector<int> suf[MAXN],pre[MAXN];
int p[MAXN];
vector<int> save[MAXN];
vector<int> G[MAXN],T[MAXN];
bool vis[MAXN];
int color[MAXN];
bool flag;
vector<int> order;
int pa[MAXLOGN][MAXN];
int depth[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)T[v].size();i++)
        if(T[v][i]!=p) dfs(T[v][i],v,d+1);
}
void init(int V)
{
    dfs(root,0,0);
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
void dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(color[to]==0) dfs_visit(to);
        else if(color[to]==1) flag=false;
	}
	color[v]=2;
	order.push_back(v);
}
void toposort()
{
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++)
		if(p[i]==i&&color[i]==0)
			dfs_visit(i);
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&fa[i]);
        if(fa[i]) T[fa[i]].push_back(i); else root=i;
    }
    init(n);
    for(int i=1;i<=k;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        suf[x[i]].push_back(y[i]);
        pre[y[i]].push_back(x[i]);
    }
    for(int i=1;i<=k;i++)
    {
        if(lca(x[i],y[i])==y[i])
        {
            puts("0");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(suf[i].size()>1||pre[i].size()>1)
        {
            puts("0");
            return 0;
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!suf[i].size()&&!pre[i].size()) {p[i]=i; vis[i]=true; save[i].push_back(i);}
        else if(suf[i].size()&&!pre[i].size())
        {
            int now=i;
            while(true)
            {
                if(vis[now])
                {
                    puts("0");
                    return 0;
                }
                vis[now]=true;
                save[i].push_back(now);
                p[now]=i;
                if(suf[now].size()) now=suf[now][0]; else break;
            }
        }
    }
    for(int i=1;i<=n;i++) {if(!vis[i]) {puts("0"); return 0;}}
    for(int i=1;i<=n;i++)
        if(fa[i])
            if(p[i]!=p[fa[i]]) G[p[fa[i]]].push_back(p[i]);
    flag=true;
    toposort();
    if(!flag) {puts("0"); return 0;}
    reverse(order.begin(),order.end());
    for(auto x:order)
        for(auto y:save[x]) 
            printf("%d ",y);
    puts("");
    return 0;
}