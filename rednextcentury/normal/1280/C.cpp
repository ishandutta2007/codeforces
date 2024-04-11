#include<bits/stdc++.h>
using namespace std;
#define ll long long
int sub[1000000];
vector<pair<int,int> > adj[1000000];
void pre(int v=1,int p=0){
    sub[v]=1;
    for (auto u:adj[v]){
        if (u.first==p)continue;
        pre(u.first,v);
        sub[v]+=sub[u.first];
    }
}
ll L=0,R=0;
void dfs(int v=1,int p=0){
    for (auto P:adj[v]){
        int u = P.first;
        if (p==u)continue;
        ll w = P.second;
        if (sub[u]%2)L+=w;
        ll left = min(sub[1]-sub[u],sub[u]);
        R+=left*w;
        dfs(u,v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        L=0,R=0;
        int n = 2*k;
        for (int i=1;i<=n;i++) adj[i].clear();
        for (int i=1;i<n;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
        pre();dfs();
        cout<<L<<' '<<R<<endl;
    }
}