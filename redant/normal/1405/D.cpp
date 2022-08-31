#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n, a, b, da, db;
vector<int> g[SZ];
bool vis[SZ];
int dp[SZ];
int mxu, mxdp;

int dfs(int u, int d) {
    dp[u]=d;
    vis[u]=true;
    if (d>mxdp) {
        mxdp=d;
        mxu=u;
    }
    for(auto &v:g[u])
        if(!vis[v]) 
            dfs(v, d+1);
}

bool solve() {
    if(db<=(2*da)) return true;
    for (int i = 1; i <= n; i++) vis[i] = false;
    mxdp=0;
    dfs(a, 0);
    if(dp[b]<=da) return true;
    for (int i = 1; i <= n; i++) vis[i] = false;
    mxdp=0;
    dfs(mxu, 0);
    return mxdp<=2*da;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b>>da>>db;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n-1; i++) {
            int u, v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<(solve()?"Alice":"Bob")<<"\n";
    }
    
    return 0;
}