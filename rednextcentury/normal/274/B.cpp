
# include <iostream>
# include <algorithm>
# include <vector>
# include <stdio.h>
using namespace std;
#define abs(x) max(x,-x);
vector<int> adj[1000000];
long long a[1000000];
int ans=0;
long long mx[1000000];
long long mn[1000000];
void dfs(int v,int p)
{
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (u==p)
            continue;
        dfs(u,v);
        mn[v]=min(mn[v],mn[u]);
        mx[v]=max(mx[v],mx[u]);
    }
    a[v]-=mx[v];
    a[v]-=mn[v];
    if (a[v]<0)
        mn[v]+=a[v];
    else
        mx[v]+=a[v];
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,-1);
    cout<<-mn[1]+mx[1]<<endl;
}