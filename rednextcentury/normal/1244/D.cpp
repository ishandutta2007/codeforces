#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cost = 0;
vector<int> adj[1000000];
ll c[3][1000000];
int col[10000000];
int best[1000000];
void dfs(int v,int p,int l1,int l2) {
    int take = 3 - l1 - l2;
    col[v]=take;
    cost+=c[take][v];
    for (auto u:adj[v])
        if (u!=p)dfs(u,v,take,l1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<3;i++)for (int j=1;j<=n;j++)cin>>c[i][j];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ok=1;
    int root=-1;
    for (int i=1;i<=n;i++){
        if (adj[i].size()>=3)ok=0;
        if (adj[i].size()==1)root=i;
    }
    if (ok==0){
        cout<<-1<<endl;
        return 0;
    }
    ll ret=1e18;
    for (int s=0;s<3;s++) {
        for (int e=0;e<3;e++){
            if (s==e)continue;
            col[root]=s;
            col[adj[root][0]]=e;
            cost=c[s][root]+c[e][adj[root][0]];
            int nxt = adj[adj[root][0]][0];
            if (nxt==root)nxt=adj[adj[root][0]][1];
            dfs(nxt,adj[root][0],e,s);
            if (cost<ret){
                ret=cost;
                for (int i=1;i<=n;i++)best[i]=col[i];
            }
        }
    }
    cout<<ret<<endl;
    for (int i=1;i<=n;i++)cout<<best[i]+1<<' ';
}