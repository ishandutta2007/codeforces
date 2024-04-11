#include<bits/stdc++.h>
using namespace std;
bool vis[1000001];
vector<int> adj[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    set<int> s;
    s.insert(1);
    vector<int> vec;
    while(!s.empty())
    {
        int v = *s.begin();
        s.erase(s.begin());
        vis[v]=1;
        vec.push_back(v);
        for (auto x:adj[v])
        {
            if (!vis[x])s.insert(x);
        }
    }
    for (auto x:vec)
        cout<<x<<' ';
}