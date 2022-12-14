#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000007
int d;
vector<int> adj[1000000];
int a[1000000];
int now;
long long dfs(int v,int p)
{
    long long ret=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (u==p)
            continue;
        if ((a[u]>a[now] || (a[now]==a[u] && u>now)) && a[u]-a[now]<=d)
            ret*=dfs(u,v)+1,ret%=MOD;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>d>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        now=i;
        ans+=dfs(i,-12321);
        ans%=MOD;
    }
    cout<<ans<<endl;
}