#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N],size[N],vis[N],ans;
vector<pair<int,int> > g[N];
void dfs(int now,int fa,int tot,int min1)
{
    size[now]=1;
    min1=min(min1,tot);
    if(tot-min1>a[now]) vis[now]=1;
    for(int i=0;i<g[now].size();i++)
    {
        int y=g[now][i].first;
        int w=g[now][i].second;
        if(y==fa) continue;
        dfs(y,now,tot+w,min1);
        size[now]+=size[y];
    }
}
 
void dfs2(int now,int fa)
{
    if(vis[now])
    {
        ans+=size[now];
        return ;
    }
    for(int i=0;i<g[now].size();i++)
    {
        if(g[now][i].first==fa) continue;
        dfs2(g[now][i].first,now);
    }
}
 
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        int to,cost;
        cin>>to>>cost;
        g[to].push_back(make_pair(i,cost));
        g[i].push_back(make_pair(to,cost));
    }
    dfs(1,0,0,0);
    dfs2(1,0);
    cout<<ans<<endl;
}