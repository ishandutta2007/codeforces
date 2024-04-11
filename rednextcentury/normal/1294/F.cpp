#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[1000000];
int ret;
int A,B,C;
int best[1000000][3];
pair<int,int> id[1000000][3];
void pre(int v,int p){
    best[v][0]=0;
    id[v][0]={v,v};
    for (auto u:adj[v]){
        if (u==p)continue;
        pre(u,v);
        if (best[u][0]+1>best[v][0]) {
            swap(best[v][1],best[v][2]);
            swap(id[v][1],id[v][2]);
            swap(best[v][0],best[v][1]);
            swap(id[v][0],id[v][1]);
            best[v][0]=best[u][0]+1;
            id[v][0]={u, id[u][0].second};
        } else if (best[u][0]+1>best[v][1]) {
            swap(best[v][1],best[v][2]);
            swap(id[v][1],id[v][2]);
            best[v][1]=best[u][0]+1;
            id[v][1]={u, id[u][0].second};
        } else if (best[u][0]+1>best[v][2]){
            best[v][2]=best[u][0]+1;
            id[v][2]={u, id[u][0].second};
        }
    }
}
void dfs(int v,int p,int longest,int lid){
    if (lid == 0)longest = 0, lid=v;
    pair<int,int> a[]={{best[v][0],id[v][0].second}, {best[v][1],id[v][1].second}, {best[v][2],id[v][2].second}, {longest, lid}};
    sort(a,a+4);
    reverse(a,a+4);
    if (a[0].first+a[1].first+a[2].first > ret){
        ret = a[0].first+a[1].first+a[2].first;
        A=a[0].second, B=a[1].second, C=a[2].second;
    }
    for (auto u:adj[v]) {
        if (u==p)continue;
        int take=1;
        if (id[v][0].first!=u)take=0;
        if (longest+1<best[v][take]+1 && id[v][take].first!=0)dfs(u, v, best[v][take]+1, id[v][take].second);
        else dfs(u,v,longest+1,lid);
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
    pre(1,0);
    dfs(1,0,0,0);
    set<int> s;
    if (A)s.insert(A);
    if (B)s.insert(B);
    if (C)s.insert(C);
    for (int i=1;i<=n;i++){
        if (s.size()==3)break;
        s.insert(i);
    }
    cout<<ret<<endl;
    for (auto x:s)cout<<x<<' ';
    cout<<endl;
}