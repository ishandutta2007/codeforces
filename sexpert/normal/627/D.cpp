#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int n, k, val[MAXN], rval[MAXN], sz[MAXN], dp[MAXN], udp[MAXN];
vector<int> adj[MAXN];

void unscrew(int s, int p = 0) {
    sz[s] = 1;
    for(auto &x : adj[s])
        if(x == p) swap(x, adj[s][(int)adj[s].size() - 1]);
    if(s > 1)
        adj[s].pop_back();
    for(auto v : adj[s]) {
        unscrew(v, s);
        sz[s] += sz[v];
    }
}

void dfs(int s) {
    dp[s] = rval[s];
    vector<int> poss;
    for(auto v : adj[s]) {
        dfs(v);
        if(dp[v] == sz[v])
            dp[s] += dp[v] * (dp[s] > 0);
        else
            poss.push_back(dp[v]);
    }
    if(!poss.empty()) {
        int m = *max_element(poss.begin(), poss.end());
        dp[s] += m * (dp[s] > 0);
    }
}

void dfs2(int s) {
    if(rval[s] == 0) {
        for(auto v : adj[s]) {
            udp[v] = 0;
            dfs2(v);
        }
        return;
    }
    int sons = adj[s].size();
    vector<int> psum(sons + 1), ssum(sons + 1), pmax(sons + 1), smax(sons + 1);
    for(int i = 1; i <= sons; i++) {
        psum[i] = psum[i - 1];
        pmax[i] = pmax[i - 1];
        int v = adj[s][i - 1];
        if(dp[v] == sz[v])
            psum[i] += sz[v];
        else
            pmax[i] = max(pmax[i], dp[v]);
    }
    for(int i = sons - 1; i >= 0; i--) {
        ssum[i] = ssum[i + 1];
        smax[i] = smax[i + 1];
        int v = adj[s][i];
        if(dp[v] == sz[v])
            ssum[i] += sz[v];
        else
            smax[i] = max(smax[i], dp[v]);
    }
    for(int i = 0; i < sons; i++) {
        int v = adj[s][i];
        int ex = max(pmax[i], smax[i + 1]);
        udp[v] = psum[i] + ssum[i + 1];
        if(udp[s] == n - sz[s])
            udp[v] += udp[s];
        else
            ex = max(ex, udp[s]);
        udp[v] += ex + 1;
    }
    for(auto v : adj[s])
        dfs2(v);
}

bool check(int m) {
    for(int i = 1; i <= n; i++)
        rval[i] = (val[i] >= m);
    dfs(1);
    dfs2(1);

    int ans = 0, cur = 0;
    for(int u = 1; u <= n; u++) {
        //cout << dp[u] << " " << udp[u] << '\n';
        if(rval[u] == 0)
            continue;
        cur = 1;
        vector<int> poss;
        for(auto v : adj[u]) {
            if(dp[v] == sz[v])
                cur += sz[v];
            else
                poss.push_back(dp[v]);
        }
        if(udp[u] == n - sz[u])
            cur += udp[u];
        else
            poss.push_back(udp[u]);
        if(poss.size())
            cur += *max_element(poss.begin(), poss.end());
        ans = max(ans, cur);
    }
    return (ans >= k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unscrew(1);
    int lo = 1, hi = 1000*1000;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}