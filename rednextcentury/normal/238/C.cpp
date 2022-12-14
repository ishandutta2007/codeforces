#include <bits/stdc++.h>
using namespace std;
int subCost[3001];
int finalCost[3001];
vector<pair<int,int> > adj[1000000];
void dfs1(int v,int pa) {
    for (auto p:adj[v]) {
        int u = p.first, c = p.second;
        if (u==pa)continue;
        dfs1(u,v);
        subCost[v]+=subCost[u]+c;
    }
}
int best=1e9;
void dfs2(int v,int pa,int cost) {
    finalCost[v]=cost+subCost[v];
    best=min(best,finalCost[v]);
    for (auto p:adj[v]) {
        int u = p.first, c=p.second;
        if (u==pa)continue;
        int newCost = cost + subCost[v] - subCost[u];
        if (c == 1) newCost--;
        else newCost++;
        dfs2(u,v,newCost);
    }

}
vector<pair<int,int> > edges;
int sol(int u,int v) {
    best = 1e9;
    memset(subCost,0,sizeof(subCost));
    memset(finalCost,0,sizeof(finalCost));
    dfs1(u,v);
    dfs2(u,v,0);
    return best;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if (n==1){
        cout<<0<<endl;
        return 0;
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    int ret = 1e9;
    for (auto e:edges) {
        int u = e.first, v = e.second;
        int c1 = sol(u,v);
        int c2 = sol(v,u);
        ret=min(ret,c1+c2);
    }
    cout<<ret<<endl;
}