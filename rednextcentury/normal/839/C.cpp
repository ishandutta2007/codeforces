#include<bits/stdc++.h>
using namespace std;
long double ret=0;
vector<int> adj[1000000];
void dfs(int v,int pa=-1, long double p = 1, int l = 0){
    int neighbors = adj[v].size();
    if (v!=1)neighbors--;
    if (!neighbors){
        ret+=l*p;
    }
    long double prob = 1.0 / neighbors;
    for (auto u:adj[v]){
        if (u!=pa){
            dfs(u, v, p*prob, l + 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<setprecision(10)<<fixed<<ret<<endl;
}