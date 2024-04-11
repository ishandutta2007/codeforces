#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a,b;
int blocks,weight;
vector<int> G[MAXN];
int sz[MAXN];
int dist[MAXN];
int tota,totb;
struct edge
{
    int u,v,w,type;
};
vector<edge> ans;
void add_edge(int u,int v,int w,int type)
{
    ans.push_back((edge){u,v,w,type});
}
P getroot(int v,int p,int t)
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void dfs(int v,int p)
{
    sz[v]=1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
void dfs1(int v,int p,int d)
{
    dist[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        int w=(tota+1)-dist[v];
        add_edge(v,to,w,0);
        tota++;
        dfs1(to,v,d+w);
    }
}
void dfs2(int v,int p,int d)
{
    dist[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        int w=(totb+1)-dist[v];
        add_edge(v,to,w,1);
        totb++;
        dfs2(to,v,d+w);
    }
}
bool cmp(int x,int y)
{
    return sz[x]>sz[y];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int root=getroot(1,0,n).S;
    dfs(root,0);
    sort(G[root].begin(),G[root].end(),cmp);
    for(auto to:G[root])
    {
        if(tota<totb)
        {
            int w=tota+1;
            add_edge(root,to,w,0);
            tota++;
            dfs1(to,root,w);
        }
        else
        {
            int w=totb+1;
            add_edge(root,to,w,1);
            totb++;
            dfs2(to,root,w);
        }
    }
    assert(tota>=(n-1)/3); assert(totb>=(n-1)/3);
    assert((tota+1)*(totb+1)-1>=2*n*n/9);
    for(auto e:ans)
    {
        if(e.type) printf("%d %d %d\n",e.u,e.v,e.w*(tota+1));
        else printf("%d %d %d\n",e.u,e.v,e.w);
    }
    return 0;
}