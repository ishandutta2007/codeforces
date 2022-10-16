/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-18 03:24:12
 ************************************************************************/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 100005
#define INF 100000000000
#define MAXLOGV 22
using namespace std;
typedef long long ll;
vector<int> G[MAXV];
vector<int> vt[MAXV];
int root;
int parent[MAXLOGV][MAXV];
int depth[MAXV],dfn[MAXV],st[MAXV];
int dp[MAXV][2];
bool marked[MAXV];
int n,q,tot;
bool f;
void add_edge(int from,int to)
{
    vt[from].push_back(to);
}
bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
void dfs(int v,int p,int d)
{
    dfn[v]=++tot;
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAXLOGV;k++)
    {
        if((depth[v]-depth[u])>>k&1)
            v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=MAXLOGV-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int build_vtree(vector<int> &a)
{
    sort(a.begin(),a.end(),cmp);
    assert(a.size()>0);
    int t=0;
    st[t++]=a[0];
    for(int i=1;i<(int)a.size();i++)
    {
        if(t==0) {st[t++]=a[i]; continue;}
        int l=lca(a[i],st[t-1]);
        //printf("l=%d\n",l);
        while(t>1&&dfn[st[t-2]]>=dfn[l]) add_edge(st[t-2],st[t-1]),t--;
        if(l!=st[t-1]) add_edge(l,st[t-1]),st[t-1]=l;
        st[t++]=a[i];
    }
    //for(int i=0;i<t;i++) printf("%d ",st[i]);
    //puts("");
    while(t>1) add_edge(st[t-2],st[t-1]),t--;
    return st[0];
}
void dfs2(int v,int p)
{
    //printf("%d %d\n",v,p);
    if(marked[v]&&parent[0][v]!=-1&&marked[parent[0][v]]) f=false;
    for(int i=0;i<(int)vt[v].size();i++)
    {
        int to=vt[v][i];
        if(to==p) continue;
        dfs2(to,v);
    }
    if(marked[v])
    {
        dp[v][1]=0;
        if(!p) dp[v][0]=0; else dp[v][0]=1;
        for(int i=0;i<(int)vt[v].size();i++)
        {
            int to=vt[v][i];
            dp[v][1]+=dp[to][0];
            dp[v][0]+=dp[to][0];
        }
    }
    else
    {
        dp[v][1]=0;dp[v][0]=1;
        int sum=0,ans=0;
        for(int i=0;i<(int)vt[v].size();i++)
        {
            int to=vt[v][i];
            sum+=dp[to][0];
            dp[v][1]+=dp[to][0];
            dp[v][0]+=min(dp[to][0],dp[to][1]);
            ans=min(ans,dp[to][1]-dp[to][0]);
        }
        dp[v][1]+=ans;
        dp[v][0]=min(dp[v][0],sum);
    }
    vt[v].clear();
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);G[y].push_back(x);
    }
    init(n);
    //for(int i=1;i<=n;i++) printf("%intd\n",dis[i]);
    scanf("%d",&q);
    vector<int> a;
    for(int i=0;i<q;i++)
    {
        int k,x;
        scanf("%d",&k);
        a.clear();
        for(int j=0;j<k;j++) 
        {
            scanf("%d",&x);
            a.push_back(x);
            marked[x]=true;
        }
        int rt=build_vtree(a);
        f=true;
        dfs2(rt,0);
        for(int j=0;j<k;j++)
            marked[a[j]]=false;
        if(!f) puts("-1"); else printf("%d\n",min(dp[rt][0],dp[rt][1]));
    }
    return 0;
}