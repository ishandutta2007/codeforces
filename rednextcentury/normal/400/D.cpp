# include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000000];
int vis[1000000];
int viss[1000000];
int color[1000000];
int ret[1001][1001];
int c[1000000];
bool can;
int cur;
void dfs(int v)
{
    vis[v]=viss[color[v]]=cur;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(vis[u])continue;
        dfs(u);
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int h=1;
    for (int i=1;i<=k;i++)
    {
        cin>>c[i];
        for (int j=0;j<c[i];j++)
            color[h++]=i;
    }
    for (int i=1;i<=k;i++)
        for (int j=1;j<=k;j++)
            if (j!=i)
                ret[i][j]=200000000;
    for (int i=0;i<m;i++)
    {
        int u,v,x;
        cin>>u>>v>>x;
        if (x==0)
            adj[u].push_back(v),adj[v].push_back(u);
        ret[color[u]][color[v]]=min(ret[color[u]][color[v]],x);
        ret[color[v]][color[u]]=min(ret[color[v]][color[u]],x);
    }
    for (int i=1;i<=n;i++)
    {
        if (can || !vis[i] && viss[color[i]])
        {
            cout<<"No"<<endl;
            return 0;
        }
        if (!vis[i])
            cur=i,dfs(i);

        if (can || !vis[i] && viss[color[i]])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (vis[i]!=viss[color[i]])
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for (int b=1;b<=k;b++)
        for (int i=1;i<=k;i++)
            for (int j=1;j<=k;j++)
                ret[i][j]=min(ret[i][j],ret[i][b]+ret[b][j]);
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=k;j++)
        {
            cout<<((ret[i][j]==200000000)?-1:ret[i][j])<<' ';
        }
        cout<<endl;
    }
}