#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[1000000];
bool vis[1000000];
int comp[1000000];
vector<int> adj[1000000];
int sz[1000000];
set<int> col[1000000];
int can[1000000];
int g[1000000];
int cur=1;
void dfs(int v)
{
    vis[v]=1;
    comp[v]=cur;
    g[cur]=v;
    sz[cur]++;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (a[u]!=a[v]){
            if (comp[u]!=0)
                col[v].insert(comp[u]);

                col[u].insert(comp[v]);
            can[a[v]]=v;
        }
        if (vis[u])continue;
        if (a[u]==a[v])dfs(u);
    }
}
int op=0;
int main()
{
    fast
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
        cin>>a[i];
    int tot=0;
    int one=0;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cur++;
            tot++;
        }
    }
    if (tot==1)
        cout<<"YES"<<endl<<1<<endl;
    else if (tot==2)
        cout<<"YES"<<endl<<can[a[1]]<<endl;
    else
    {
        int num=0,id=0;
        for (int i=1;i<=n;i++)
            if (col[i].size()==tot-1)
                id=i;
        if (id==0)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl<<id<<endl;
        }
    }
}