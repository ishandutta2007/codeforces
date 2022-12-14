#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x[10000];
int y[10000];
vector<int> adj[100000];
int sub[1000000];
void dfs(int v=1,int pa=0){
    sub[v]=1;
    for (auto u:adj[v]){
        if (u==pa)continue;
        dfs(u,v);
        sub[v]+=sub[u];
    }
}
int ret[100000];
void solve(int v, vector<pair<int,int> > points, int pa=0){
    if (points.size()==1){
        ret[points[0].second]=v;
        return;
    }
    sort(points.begin(),points.end());
    reverse(points.begin(),points.end());
    int root = points[points.size()-1].second;
    ret[root]=v;
    points.pop_back();
    vector<pair<double,int> > angles;
    for (auto p:points){
        int id = p.second;
        double angle  = atan2(y[id]-y[root], x[id]-x[root]);
        angles.emplace_back(angle,id);
    }
    sort(angles.begin(),angles.end());
    for (auto u:adj[v]){
        if (u==pa)continue;
        int num = sub[u];
        vector<pair<int,int> > pts;
        while(num--){
            auto cur = angles.back();
            angles.pop_back();
            pts.emplace_back(y[cur.second], cur.second);
        }
        solve(u, pts, v);
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
    vector<pair<int,int> > vec;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        vec.emplace_back(y[i],i);
    }
    dfs();
    solve(1, vec);
    for (int i=1;i<=n;i++)cout<<ret[i]<<' ';
    cout<<endl;
}