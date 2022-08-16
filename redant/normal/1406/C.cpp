#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n;
vector<int> G[SZ];
int x[SZ], y[SZ];
int id;
int gc0, gc1, gcmin;
bool vis[SZ];

int dfs(int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    int cmax = 0, ctot = 0;
    x[u]=id++;
    for (auto v : G[u]) {
        if (!vis[v]) {
            int cc = dfs(v);
            cmax = max(cmax, cc);
            ctot += cc;
        }
    }
    y[u]=id;
    cmax = max(cmax, n-1-ctot);
    // cout<<"u="<<u<<". "<<cmax<<"\n";
    if (cmax < gcmin) {
        gc0=u;
        gc1=-1;
        gcmin = cmax;
    }
    else if (cmax == gcmin) {
        gc1 = u;
    }
    return 1 + ctot;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            G[i+1].clear();
            vis[i+1] = false;
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        gc0=-1; gc1=-1; gcmin=n;
        id=0;
        dfs(1);
        // cout<<gc0<<" "<<gc1<<"\n";
        if (gc1 == -1) {
            cout<<"1 "<<G[1][0]<<"\n";
            cout<<"1 "<<G[1][0]<<"\n";
        } else {
            int other=-1;
            for (auto v : G[gc1]) {
                if (gc0!=v) {
                    other=v;
                    break;
                }
            }
            cout<<gc1<<" "<<other<<"\n";
            cout<<gc0<<" "<<other<<"\n";
        }
    }
    
    return 0;
}