#include <bits/stdc++.h>
using namespace std;
int subCost[1000000];
int finalCost[1000000];
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
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    dfs1(1,-1);
    dfs2(1,-1,0);
    vector<int> vec;
    for (int i=1;i<=n;i++) {
        if (finalCost[i]==best)
            vec.push_back(i);
    }
    cout<<best<<endl;
    for (auto v:vec)
        cout<<v<<' ';
    cout<<endl;
}