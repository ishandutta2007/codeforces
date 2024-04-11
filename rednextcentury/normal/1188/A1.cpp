#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000000];
bool ok =1;
bool leaf[1000000];
int root;
int leaves=0;
void dfs(int v,int p=0){
    leaf[v]=1;
    for (auto u:adj[v]){
        if (u==p)continue;
        leaf[v]=0;
        dfs(u,v);
    }
    int num=0;
    for (auto u:adj[v]){
        if (u==p)continue;
        num++;
    }
    if (!leaf[v])if (adj[v].size()<=2)ok=0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++)if (adj[i].size()>1)root=i;
    dfs(root);
    if (ok)cout<<"YES\n";
    else cout<<"NO\n";
}