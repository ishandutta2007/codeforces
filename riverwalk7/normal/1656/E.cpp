#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
int N;
vector<int> conn[MAXN];
int a[MAXN];
int level[MAXN];
int par[MAXN];
int T, u, v;
void dfs(int node)
{
    int childcount = 0;
    for(int i=0; i<conn[node].size(); i++)
    {
        if(conn[node][i] != par[node])
        {
            par[conn[node][i]] = node;
            level[conn[node][i]] = level[node]+1;
            ++childcount;
            dfs(conn[node][i]);
        }
    }
    if(level[node] == 0)
    {
        a[node] = childcount;
    }
    else if(level[node] % 2 == 0)
    {
        a[node] = childcount+1;
    }
    else
    {
        a[node] = -childcount-1;
    }
}
void solve()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        conn[i].clear();
    }
    for(int i=0; i<N-1; i++)
    {
        cin>>u>>v;
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    dfs(1);
    for(int i=1; i<=N; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<""<<endl;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        solve();
    }
}