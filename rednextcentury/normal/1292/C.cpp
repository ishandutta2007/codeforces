#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ret=0;
vector<int> adj[1000000];
int root[2];
ll sub[1000000];
 
int pre(int v, int p, int dep=0){
    sub[v]=1;
    int mxDep = dep;
    for (auto u:adj[v]){
        if (u==p || u==root[0] || u==root[1])continue;
        mxDep = max(mxDep, pre(u,v, dep+1));
        sub[v]+=sub[u];
    }
    return mxDep;
}
ll dp[3001][3001];
ll solve(int l, int r, int pl, int pr){
    if (dp[l][r]!=-1)return dp[l][r];
    dp[l][r]=0;
    for (auto u:adj[l]) {
        if (u==pl)continue;
        dp[l][r]=max(dp[l][r], solve(u, r, l, pr) + sub[r]*sub[u]);
    }
    for (auto u:adj[r]) {
        if (u==pr)continue;
        dp[l][r]=max(dp[l][r], solve(l, u, pl, r) + sub[l]*sub[u]);
    }
    return dp[l][r];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int,int> > E;
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        E.emplace_back(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx=-1;
    vector<pair<int,int> > best;
    for (auto e:E) {
        root[0] = e.first;
        root[1] = e.second;
        int L = pre(root[0], -1);
        int R = pre(root[1], -1);
        if (L+R == mx)best.push_back(e);
        else if (L+R>mx)best.clear(), best.push_back(e), mx = L+R;
    }
memset(dp,-1,sizeof(dp));
    //cout<<best.size()<<endl;
    for (auto e:E){
        root[0] = e.first;
        root[1] = e.second;
        int L = pre(root[0], -1);
        int R = pre(root[1], -1);
        //memset(dp,-1,sizeof(dp));
        ret=max(ret, solve(root[0], root[1], root[1], root[0]) + sub[root[0]]*sub[root[1]] );
    }
    cout<<ret<<endl;
}