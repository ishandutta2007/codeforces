#include <bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> vec;
int deg[1000000];
vector<int> adj[1000000];
int ans[1000000];
int main ()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++;
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (deg[i]==0)
            s.insert(-i);
    for (int i=0;i<n;i++)
    {
        int v = -(*s.begin());
        ans[v]=n-i;
        s.erase(s.begin());
        for (int j=0;j<adj[v].size();j++)
            if (--deg[adj[v][j]]==0)
                s.insert(-adj[v][j]);
    }
    for (int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}