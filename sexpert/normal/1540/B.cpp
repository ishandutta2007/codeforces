#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 205;
const ll MOD = 1e9 + 7;

ll mem[MAXN][MAXN];
ll inv[MAXN];
int dis[MAXN][MAXN];
int inp[MAXN], vis[MAXN];
vector<int> adj[MAXN];

ll _inv(ll b) {
    ll e = MOD - 2, r = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) r = (r * b) % MOD;
        b = (b * b) % MOD;
    }
    return r;
}

ll dp(int l, int r) {
    if(l == 0)
        return 1;
    if(r == 0)
        return 0;
    if(mem[l][r] != -1)
        return mem[l][r];
    ll ans = (dp(l - 1, r) + dp(l, r - 1)) % MOD;
    return mem[l][r] = (ans * inv[2]) % MOD;
}

int dfs(int s) {
    int res = 1;
    vis[s] = 1;
    for(auto v : adj[s]) {
        if(inp[v])
            continue;
        if(vis[v])
            continue;
        res += dfs(v);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(mem, -1, sizeof mem);
    for(int i = 1; i < MAXN; i++)
        inv[i] = _inv(i);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            dis[i][j] = MOD;
        dis[i][i] = 0;
    }

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        dis[u][v] = dis[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    ll ans = 0;

    for(int u = 1; u <= n; u++) {
        for(int v = u + 1; v <= n; v++) {
            for(int w = 1; w <= n; w++) {
                vis[w] = 0;
                if(dis[w][u] + dis[w][v] == dis[u][v])
                    inp[w] = 1;
                else
                    inp[w] = 0;
            }
            for(int w = 1; w <= n; w++) {
                if(!inp[w])
                    continue;
                ll x = dfs(w);
                ans = (ans + ((dp(dis[w][v], dis[w][u]) * inv[n]) % MOD * x) % MOD) % MOD;
            }
        }
    }

    cout << ans << '\n';
}