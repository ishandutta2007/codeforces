#include<bits/stdc++.h>
using namespace std;
#define ll long long
int p[1000000];
vector<int> adj[1000000];
vector<int> Q[1000000];
int score[1000000];
int need[1000000];
bool is[1000000];
void pre(int v,int pa){
    for (auto u:adj[v]){
        if (u==pa)continue;
        p[u]=v;
        pre(u,v);
    }
}
void dfs(int v){
    for (auto x:Q[v]) if ((++score[x])==need[x])is[x]=1;
    for (auto u:adj[v]){
        if (u==p[v])continue;
        dfs(u);
    }
    for (auto x:Q[v]) if ((--score[x])==need[x])is[x]=1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre(1,-1);
    for (int i=1;i<=m;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int x;
            cin>>x;
            if (x!=1)x=p[x];
            Q[x].push_back(i);
        }
        need[i]=k;
    }
    dfs(1);
    for (int i=1;i<=m;i++){
        if (is[i])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}