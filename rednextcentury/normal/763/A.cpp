#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
int mn[1000000];
int mx[1000000];
int c[1000000];
bool vis[1000000];
int ret=-1;
bool ok[1000000];
void dfs(int v,int p)
{
    mn[v]=mx[v]=c[v];
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (u==p)continue;
        dfs(u,v);
        mn[v]=min(mn[v],mn[u]);
        mx[v]=max(mx[v],mx[u]);
    }
    if (mn[v]==mx[v])ok[v]=1;
}
vector<int> premn[1000000],premx[1000000],sufmn[1000000],sufmx[1000000];
void transition(int v,int l,int r)
{
    vis[v]=1;
    bool is=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])
        {
            if (i>0)
                premn[v][i]=premn[v][i-1],premx[v][i]=premx[v][i-1];
            continue;
        }
        is=is&ok[u];
        if (i==0)
            premn[v][i]=mn[u],premx[v][i]=mx[u];
        else
            premn[v][i]=min(mn[u],premn[v][i-1]),premx[v][i]=max(premx[v][i-1],mx[u]);
    }
    if (is && l==r)
        ret=v;
    for (int i=adj[v].size()-1;i>=0;i--)
    {
        int u=adj[v][i];
        if (vis[u])
        {
            if (i+1<adj[v].size())
                sufmn[v][i]=sufmn[v][i+1],sufmx[v][i]=sufmx[v][i+1];
            continue;
        }
        if (i+1==adj[v].size())
            sufmn[v][i]=mn[u],sufmx[v][i]=mx[u];
        else
            sufmn[v][i]=min(mn[u],sufmn[v][i+1]),sufmx[v][i]=max(sufmx[v][i+1],mx[u]);
    }
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        int L=l,R=r;
        if (i>0)L=min(L,premn[v][i-1]),R=max(R,premx[v][i-1]);
        if (i+1<adj[v].size()) L=min(L,sufmn[v][i+1]),R=max(R,sufmx[v][i+1]);
        L=min(L,c[v]);
        R=max(R,c[v]);
        transition(u,L,R);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        premn[u].push_back(10000000);
        premx[u].push_back(0);
        sufmn[u].push_back(10000000);
        sufmx[u].push_back(0);
        premn[v].push_back(10000000);
        premx[v].push_back(0);
        sufmn[v].push_back(10000000);
        sufmx[v].push_back(0);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        cin>>c[i];
    dfs(1,-1);
    transition(1,c[1],c[1]);
    if (ret==-1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl<<ret<<endl;
}