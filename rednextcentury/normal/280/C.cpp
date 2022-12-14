#include <bits/stdc++.h>
#define ll long long
using namespace std;
long double ret=0;
vector<int> adj[1000000];
void dfs(int v,int dep,int pa)
{
    ret+=1.0/dep;
    for (auto u:adj[v])
        if (u!=pa)
            dfs(u,dep+1,v);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i+1<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1,0);
    cout<<setprecision(10)<<fixed<<ret<<endl;
}