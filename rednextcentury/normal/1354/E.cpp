#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> adj[100000];
int c[2];
int col[100000];
int vis[100000];
bool ok = 1;
vector<int> z;
vector<int> o;
void dfs(int v,int cc){
    col[v]=cc;
    if (cc==0)z.push_back(v);
    else o.push_back(v);
    c[cc]++;
    vis[v]=1;
    for (auto u:adj[v]){
        if (vis[u] && col[u]==col[v])ok=0;
        if (vis[u])continue;
        dfs(u,1-cc);
    }
}
vector<vector<int> > zeros, ones;
vector<pair<int,int> > cnt;
bool dp[5001][5001];
bool vv[5001][5001];
bool solve(int i,int j){
    if (j<0)return 0;
    if (i==cnt.size()) return j==0;
    if (vv[i][j])return dp[i][j];
    vv[i][j]=1;
    if (solve(i+1, j - cnt[i].first)) dp[i][j]=1;
    if (solve(i+1, j-cnt[i].second)) dp[i][j]=1;
    return dp[i][j];
}
char ret[100000];
void path(int i,int j){
    if (i==cnt.size())return;
    if (solve(i+1, j - cnt[i].first)) {
        for (auto x:zeros[i]) ret[x] = '2';
        for (auto x:ones[i]) ret[x] = '1';
        path(i+1, j-cnt[i].first);
        return;
    }
    if (solve(i+1, j - cnt[i].second)) {
        for (auto x:zeros[i]) ret[x] = '1';
        for (auto x:ones[i]) ret[x] = '2';
        path(i+1, j-cnt[i].second);
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n,m;
        cin>>n>>m;
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        int odd = n1+n3;
        int even = n2;
        for (int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=1;i<=n;i++){
            if (!vis[i]){
                c[0]=c[1]=0;
                z.clear();
                o.clear();
                dfs(i,0);
                zeros.push_back(z);
                ones.push_back(o);
                cnt.push_back({c[0],c[1]});
            }
        }
        if (!solve(0, n2) || !ok) cout<<"NO"<<endl;
        else {
            path(0,n2);
            cout<<"YES"<<endl;
            for (int i=1;i<=n;i++){
                if (ret[i]=='1' && n3){
                    n3--;
                    ret[i]='3';
                }
                cout<<ret[i];
            }
            cout<<endl;
        }
}