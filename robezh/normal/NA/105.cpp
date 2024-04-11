#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll INF = (ll)1e18;

struct edge {
    int to;
    ll cost;
    int id;
};

int n, rt;
vector<edge> G[N];
int cut_id = -1;
int vis[N];
int cyc[N], cyc_len = 0;;
ll wei[N], len[N];
ll out_dia = 0, in_dia = 0;
ll dp[2][N];
ll cmax[N], ccmax[N];
ll cdia[N], ccdia[N];
int in_cyc[N];

int dfs(int v, int e_id) {
    if(vis[v]) {rt = v; return 1;}

    vis[v] = 1;
    for(auto e : G[v]) {
        if(e.id == e_id) continue;
        if(dfs(e.to, e.id) == 1) {
            wei[cyc_len] = e.cost;
            in_cyc[e.to] = 1;
            cyc[cyc_len++] = e.to;
            vis[v] = 1;
            if(rt == v) cut_id = e.id;
            return rt != v;
        }
    }
    return 0;
}

ll dfs_depth(int v, int p) {
    for(auto e : G[v]) {
        if(in_cyc[e.to] || e.to == p) continue;
        ll cur = e.cost + dfs_depth(e.to, v);
        if(cur > dp[0][v]) swap(cur, dp[0][v]);
        if(cur > dp[1][v]) swap(cur, dp[1][v]);
    }
    out_dia = max(out_dia, dp[0][v] + dp[1][v]);
    return dp[0][v];
}

ll get_diameter(int v, int p) {
    ll mx0 = 0, mx1 = 0;
    for(auto e : G[v]) {
        if(e.to == p || e.id == cut_id) continue;
        ll cur = e.cost + get_diameter(e.to, v);
        if(cur > mx0) swap(cur, mx0);
        if(cur > mx1) swap(cur, mx1);

    }
    in_dia = max(in_dia, mx0 + mx1);
    return mx0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        G[u].push_back({v, cost, i});
        G[v].push_back({u, cost, i});
    }
    dfs(0, -1);

    for(int i = 0; i < cyc_len; i++) len[i] = dfs_depth(cyc[i], -1);
    ll best = cmax[0] = len[0];
    cdia[0] = 0;
    ll cost_sum = 0;
    for(int i = 1; i < cyc_len; i++) {
        cost_sum += wei[i-1];
        cmax[i] = max(cmax[i-1], cost_sum + len[i]);
        cdia[i] = max(cdia[i-1], len[i] + cost_sum + best);
        best = max(best, len[i] - cost_sum);
    }
    best = ccmax[cyc_len - 1] = len[cyc_len - 1];
    ccdia[cyc_len - 1] = 0;
    cost_sum = 0;
    for(int i = cyc_len - 2; i >= 0; i--) {
        cost_sum += wei[i];
        ccmax[i] = max(ccmax[i+1], cost_sum + len[i]);
        ccdia[i] = max(ccdia[i+1], len[i] + cost_sum + best);
        best = max(best, len[i] - cost_sum);
    }
    ll res = INF;
    for(int i = 0; i <= cyc_len - 2; i++) {
        res = min(max(max(ccmax[i+1] + cmax[i] + wei[cyc_len - 1], cdia[i]), ccdia[i+1]), res);
    }
    get_diameter(0, -1);
    res = min(res, in_dia);
    cout << max(res, out_dia) << endl;
}