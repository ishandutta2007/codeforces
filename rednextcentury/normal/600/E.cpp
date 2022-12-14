#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;

long long ans;
long long sum;
long long ret[N];
void add(int v);

// Don't change
vector<int> adj[N];
int sz[N];
int cnt[N];
int col[N];
int st[N];
int en[N];
int node[N];

int tim=0;
void init(int v=1,int p=-1)
{
    cnt[v]=0;
    sz[v]=1;
    node[tim]=v;
    st[v]=tim++;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (u==p)
            continue;
        init(u,v);
        sz[v]+=sz[u];
    }
    en[v]=tim;
}
void dfs(int v=1,int p=-1,bool keep=0)
{
    int mx=-1;
    int big=-1;
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(u!=p && sz[u] > mx)
          mx = sz[u], big = u;
    }
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(u != p && u != big)
            dfs(u, v, 0);
    }
    if(big != -1)
        dfs(big, v, 1);
    for(int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if(u!=p && u!=big)
            for(int p = st[u]; p < en[u]; p++)
                add(node[p]);
    }
    add(v);
    ret[v]=sum;
    if(keep == 0)
    {
        for(int p = st[v]; p < en[v]; p++)
            cnt[col[node[p]]]--;
        ans=0,sum=0;
    }
}
// Change
void add(int v)
{
    cnt[col[v]]++;
    if (cnt[col[v]]>ans)
        ans=cnt[col[v]] , sum=col[v];
    else if (cnt[col[v]]==ans)
        sum+=col[v];
}

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>col[i];
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init();
    dfs();
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}