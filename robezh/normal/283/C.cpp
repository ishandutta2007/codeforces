#include <bits/stdc++.h>
using namespace std;

const int N = 305, mod = (int)1e9 + 7, M = (int)1e5 + 50;

int n, q, t;
int dp[M], a[N];
bool mad[N];
int nxt[N];
int vis[N];

void dfs(int v) {
    vis[v] = -1;
    if(nxt[v] == -1) {
        vis[v] = 1;
        return ;
    }
    if(vis[nxt[v]] == -1) {
        cout << 0 << endl;
        exit(0);
    }
    if(vis[nxt[v]] == 0) dfs(nxt[v]);
    a[v] += a[nxt[v]];
    vis[v] = 1;
}

int main() {
    cin >> n >> q >> t;
    memset(nxt, -1, sizeof(nxt));
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; u--, v--;
        nxt[v] = u;
        mad[u] = true;
    }
    for(int i = 0; i < n; i++) if(vis[i] == 0) dfs(i);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        if(mad[i]) {
            for(int j = t; j >= 0; j--) {
                if(j >= a[i]) dp[j] = dp[j - a[i]];
                else dp[j] = 0;
            }
        }
        for(int j = 0; j + a[i] <= t; j++) {
            dp[j + a[i]] += dp[j];
            dp[j + a[i]] %= mod;
        }
    }
    cout << dp[t] << endl;
}