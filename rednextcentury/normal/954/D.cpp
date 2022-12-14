#include<bits/stdc++.h>
using namespace std;
int d[2][1000000];
#define ll long long
vector<int> adj[1000000];
int n,m;
void bfs(int v, int o){
    for (int i=1;i<=n;i++)
        d[o][i]=1e9;
    d[o][v]=0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for (auto u:adj[v])
        {
            if (d[o][u]<1e7)continue;
            d[o][u]=d[o][v]+1;
            q.push(u);
        }
    }
}
bool has[2000][2000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        has[u][v]=1;
        has[v][u]=1;
    }
    bfs(s,0);
    bfs(t,1);
    int ret=0;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++){
            if (has[i][j] || i==j)continue;
            if (min(d[0][i]+1+d[1][j], d[0][j]+1+d[1][i])>=d[0][t])ret++;
        }
    }
    cout<<ret<<endl;
}