# include <iostream>
# include <vector>
using namespace std;
int ans=0;
int now=1;
int cur=0;
bool vi[10000];
vector<int> adj[1000000];
int vis[1000000];
int num[1000000];
void dfs(int v,int h)
{
    vis[v]=h;
    int n=adj[v].size();
    int mx1=0,mx2=0;
    num[v]=0;
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vis[u]>=now-1)continue;
        dfs(u,h);
        num[v]=max(num[u],num[v]);
        if (num[u]>mx1)
        {
            mx2=mx1;
            mx1=num[u];
        }
        else if (num[u]>mx2)
            mx2=num[u];
    }
    num[v]++;
    cur=max(cur,mx1+mx2+1);
}
void solve(int v)
{
    vi[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (vi[u])continue;
        int f=1;
        vis[v]=now+1;
        vis[u]=now+2;
        cur=0;
        now+=2;
        dfs(v,now-1);
        f*=cur-1;
        cur=0;
        dfs(u,now);
        f*=cur-1;
        ans=max(ans,f);
        solve(u);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    cout<<ans<<endl;
}