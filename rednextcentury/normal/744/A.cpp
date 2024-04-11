#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
vector<int> groups[1000000];
bool vis[1000000];
bool is[1000000];
bool has[1000000];
bool Adj[1003][1003];
int cur;
void dfs(int v)
{
    vis[v]=1;
    if (is[v])has[cur]=1;
    groups[cur].push_back(v);
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
    }
}
int c[1000000];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<k;i++)
        cin>>c[i],is[c[i]]=1;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        Adj[x][y]=Adj[y][x]=1;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cur++;
        }
    }
    int mx=0,id=-1;
    for (int i=0;i<cur;i++)
    {
        if (has[i] && groups[i].size()>mx)
            mx=groups[i].size(),id=i;
    }
    for (int i=0;i<cur;i++)
    {
        if (!has[i])
        {
            for (int j=0;j<groups[i].size();j++)
            {
                groups[id].push_back(groups[i][j]);
            }
            groups[i].clear();
        }
    }
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<groups[i].size();j++)
        {
            for (int x=j+1;x<groups[i].size();x++)
                if (!Adj[groups[i][j]][groups[i][x]])
                    Adj[groups[i][j]][groups[i][x]]=1,Adj[groups[i][x]][groups[i][j]]=1,ans++;
        }
    }
    cout<<ans<<endl;
}