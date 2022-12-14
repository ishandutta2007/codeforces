#include <bits/stdc++.h>
using namespace std;

int h[1000000],cnt[1000000],sz[1000000],ans[1000000];
int cnt2[1000000];
vector<int> adj[1000000];
vector<pair<int,int> > query[1000000];
int BIT[1000000];
int n;
void update(int x, int delta)
{
    x++;
    for(; x <= 100002; x += x&-x)
          BIT[x] += delta;
}
int Q(int x)
{
    if (x<0)return 0;
    x++;
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}
void pre(int v=0,int pa=-1)
{
    sz[v] = 1;
    for(auto u:adj[v])
        if (u!=pa)
            pre(u,v),sz[v] += sz[u];
}
bool bad[1000000];
int num;
void add(int v,int p,int x=1)
{
    update(cnt2[h[v]],-1);
    cnt2[h[v]]+=x;
    update(cnt2[h[v]],+1);
    for(auto u:adj[v])
        if(!bad[u] && u!=p)
            add(u,v,x);
}
bool vis[1000000];
void dfs(int v=0,bool cl=1,int p=-1){

    int mx=-1,node=-1;
    for(auto u:adj[v])
        if(u!=p && sz[u]>mx)
            mx=sz[u], node = u;
    for(auto u:adj[v])
        if(u != node && u!=p)
            dfs(u,1,v);
    if(node!=-1)
        bad[node]=1,dfs(node,0,v);
    add(v,p);
    if (node!=-1)bad[node]=0;
    for(auto q:query[v])
        ans[q.second] = num-Q(q.first-1);
    if(cl)
        add(v,p,-1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>h[i];
        if (++cnt[h[i]]==1)num++;
    }
    update(0,num);
    for (int i=0;i+1<n;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre();
    for (int i=0;i<m;i++)
    {
        int v,k;
        cin>>v>>k;
        v--;
        query[v].push_back({k,i});
    }
    dfs();
    for (int i=0;i<m;i++)
        cout<<ans[i]<<'\n';
}