#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int D[1000000];
int P[1000000];
struct edge
{
    int u,v;
};
vector<edge> edges[1000000];
vector<int> adj[1000000];
vector<int> b[1000000];
vector<int> c[1000000];
int B;
int vis[1000000];
int best[1000000][2];
int cur;
void dfs(int v)
{
    best[v][0]=0,best[v][1]=0;
    vis[v]=cur;
    for (auto u:adj[v])
    {
        if (vis[u]==cur)continue;
        dfs(u);
        if (best[u][0]>best[v][0])
        {
            swap(best[v][1],best[v][0]);
            best[v][0]=best[u][0];
        }
        else if (best[u][0]>best[v][1])
            best[v][1]=best[u][0];
    }
    B=max(B,best[v][0]+best[v][1]+1);
    best[v][0]++;
    best[v][1]++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    D[1]=1;
    for (int i=2;i<=200000;i++)
    {
        if (!P[i])
        {
            D[i]=i;
            for (int j=i+i;j<=200000;j+=i)
            {
                if (D[j]==0)D[j]=i;
                P[j]=1;
            }
        }
    }
    set<int> all;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        while(x!=1)
        {
            int y=D[x];
            b[i].push_back(y);
            c[y].push_back(i);
            all.insert(y);
            while(x%y==0)
                x/=y;
        }
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        int l=0,r=0;
        while(l<b[u].size() && r<b[v].size())
        {
            if (b[u][l]==b[v][r])
            {
                edge x;
                x.u = u;
                x.v = v;
                edges[b[u][l]].push_back(x);
                l++,r++;
            }
            else if (b[u][l]<b[v][r])l++;
            else r++;
        }
    }
    int last=-1;
    int ret=0;
    for (auto x:all)
    {
        if (last!=-1)
        {
            for (auto y:c[last])
                adj[y].clear();
        }
        for (auto y:edges[x])
        {
            adj[y.u].push_back(y.v);
            adj[y.v].push_back(y.u);
        }
        cur++;
        last=x;
        for (auto y:c[x])
        {
            if (vis[y]!=cur)
            {
                B=0;
                dfs(y);
                ret=max(ret,B);
            }
        }
    }
    cout<<ret<<endl;
}