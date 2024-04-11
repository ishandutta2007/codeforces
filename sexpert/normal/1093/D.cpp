#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const long long MOD = 998244353;
vector<int> adj[MAXN];
int vist[MAXN], color[MAXN], blacks, whites;
long long powt[MAXN];
bool bip;

void dfs(int src, int col) {
    color[src] = col;
    if(col == 0)
        blacks++;
    else
        whites++;
    vist[src] = 1;
    for(auto v : adj[src]) {
        if(!vist[v])
            dfs(v, 1 - col);
        else {
            if(color[src] == color[v])
                bip = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    powt[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        powt[i] = (2*powt[i - 1])%MOD;
    }
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n + 1; i++) {
            adj[i].clear();
            vist[i] = 0;
            color[i] = 0;
        }
        while(m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            if(!vist[i]) {
                bip = true;
                blacks = 0;
                whites = 0;
                dfs(i, 0);
                if(!bip) {
                    ans = 0;
                    break;
                }
                ans = ((ans)*((powt[blacks] + powt[whites])%MOD))%MOD;
            }
        }
        cout << ans << endl;
    }
}