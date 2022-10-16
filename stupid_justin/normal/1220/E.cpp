#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define int long long
using namespace std;
const int N=2e5+5;
vector<int> vec[N];
int w[N],s[N];
int mark[N],vis[N],pre[N];

void dfs(int v)
{
    vis[v]=1;
    for(int j=0;j<vec[v].size();j++)
    {
        int u=vec[v][j];
        if(vis[u])
        {
            if(u!=pre[v])
            {
                mark[v]=1;
            }
        }
        else
        {
            pre[u]=v;
            dfs(u);
            if(mark[u]) mark[v]=1;
            else s[v]=max(s[u],s[v]);
        }
    }
    if(!mark[v])
        s[v]+=w[v];
    return;
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int t;
    cin>>t;
    dfs(t);
    int ans=0,maxx=0;
    for(int i=1;i<=n;i++)
    {
        if(mark[i])
            ans+=w[i];
        maxx=max(maxx,s[i]);
    }
    ans+=maxx;
    cout<<ans<<endl;
}