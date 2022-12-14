#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int> > adj[100000];
vector<int> G;
int a[100000];
int st;
int val;
void dfs(int v,int pa){
    for (auto p:adj[v]){
        int u = p.first;
        int id=p.second;
        if (u==pa)continue;
        if (a[u]>val)G.push_back(id);
        dfs(u,v);
    }
}
int dp[1000000];
int V[1000000];
int node[100000];
int P[100000];
int DP(int v){
    if (dp[v]!=-1)return dp[v];
    int ret=1;
    G.clear();
    st = v;
    val = V[v];
    dfs(node[v],P[v]);
    vector<int> nb = G;
    for (auto u:nb){
        ret=max(ret, DP(u)+1);
    }
    return dp[v]=ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    int ID=0;
    for (int i=0;i+1<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,ID});
        ID++;
        adj[v].push_back({u,ID});
        ID++;
    }

    for (int i=1;i<=n;i++){
        V[ID] = a[i];
        P[ID] = i;
        node[ID++]=i;
    }
    for (int i=1;i<=n;i++){
        for (auto p:adj[i]){
            int u = p.first;
            int id = p.second;
            st = id;
            V[id] = a[u];
            node[id] = u;
            P[id]=i;
        }
    }
    memset(dp,-1,sizeof(dp));
    int ret=0;
    for (int i=0;i<=ID;i++){
        ret=max(ret,DP(i));
    }
    cout<<ret<<endl;
}