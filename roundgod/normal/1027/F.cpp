/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 23:41:02
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],aa[MAXN],bb[MAXN];
vector<int> vv;
vector<int> G[2*MAXN];
vector<int> rG[2*MAXN];
vector<int> vs;
int mx[2*MAXN],mx2[2*MAXN];
bool used[2*MAXN],vis[2*MAXN];
int cmp[2*MAXN];
int vcnt[2*MAXN],ecnt[2*MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=2*n;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&a[i],&b[i]);
        vv.push_back(a[i]);vv.push_back(b[i]);
    }
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    for(int i=1;i<=n;i++)
    {
        int u=lower_bound(vv.begin(),vv.end(),a[i])-vv.begin()+1;
        int v=lower_bound(vv.begin(),vv.end(),b[i])-vv.begin()+1;
        aa[i]=u;bb[i]=v;
        add_edge(u,v);add_edge(v,u);
    }
    int p=scc();
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        int bl=cmp[aa[i]];
        if(!vis[aa[i]]) 
        {
            vcnt[bl]++;
            if(a[i]>mx[bl])
            {
                mx2[bl]=mx[bl];
                mx[bl]=a[i];
            }
            else if(a[i]>mx2[bl]) mx2[bl]=a[i];
        }
        vis[aa[i]]=true;
        if(!vis[bb[i]]) 
        {
            vcnt[bl]++;
            if(b[i]>mx[bl])
            {
                mx2[bl]=mx[bl];
                mx[bl]=b[i];
            }
            else if(b[i]>mx2[bl]) mx2[bl]=b[i];
        }
        vis[bb[i]]=true;
        ecnt[bl]++;
    }
    int res=0;
    for(int i=0;i<p;i++)
    {
        if(ecnt[i]>vcnt[i])
        {
            puts("-1");
            return 0;
        }
        else if(ecnt[i]==vcnt[i]-1) res=max(res,mx2[i]);
        else res=max(res,mx[i]);
    }
    printf("%d\n",res);
    return 0;
}