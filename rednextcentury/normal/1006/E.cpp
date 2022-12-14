#include <bits/stdc++.h>
using namespace std;
int S[1000000];
int E[1000000];
int node[1000000];
vector<int> adj[1000000];
int tim=0;
void dfs(int v)
{
    S[v]=tim++;
    node[S[v]]=v;
    for (auto u:adj[v])dfs(u);
    E[v]=tim-1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    for (int i=1;i<=n;i++)
        sort(adj[i].begin(),adj[i].end());
    dfs(1);
    while(q--)
    {
        int u,k;
        cin>>u>>k;
        int t = S[u]+k-1;
        if (t<=E[u])t=node[t];
        else t=-1;
        cout<<t<<endl;
    }
}