// In the name of God

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = (int) 4e5 + 5, mod = 0;
int a[N], b[N], es[N], et[N], ew[N], up[N], to_up[N], mark[N], ed, res[N];
vector<int> cycle, adj[N];
int other(int e, int v) {
    return es[e] ^ et[e] ^ v;
}
bool find_cycle(int v, int p, int ep = -1, int to = 0) {
    if (up[v] >= 0) return 1;
    up[v] = p;
    to_up[v] = to;
    for (int e : adj[v])
        if (ep != e && find_cycle(other(e, v), v, e, ew[e]) && !cycle.size()) {
            int u = other(e, v), w = v;
            while (w != u) {
                b[(int) cycle.size()] = to_up[w];
                cycle.push_back(w);
                w = up[w];
            }
            b[(int) cycle.size()] = ew[e];
            cycle.push_back(u);
            for (int x : cycle) {
                mark[x] = 1;
            }
        }
    return 0;
}

int lead[N], dep[N], dp[N], sz[N];
void dfs_down(int v, int p) {
    sz[v] = 1;
    for (int e : adj[v]) if (!mark[other(e, v)] && p != other(e, v)) {
        int u = other(e, v), w = ew[e];
        dep[u] = dep[v] + w;
        lead[u] = lead[v];
        dfs_down(u, v);
        sz[v] += sz[u];
        dp[v] += sz[u] * w + dp[u];
    }
}
void dfs_up(int v, int p, int cur_val = 0) {
    int n = sz[lead[v]], sum = 0;
    res[v] += cur_val;
    res[v] += dp[v];
    for (int e : adj[v]) if (!mark[other(e, v)] && p != other(e, v)) {
        int u = other(e, v), w = ew[e];
        dfs_up(u, v, cur_val + dp[v] - dp[u] - sz[u] * w + w * (n - sz[u]));
    }
}
int handle_res[N], res_cycle[N], cnt[N], ps[N];
void handle(int n, int add = 0) {
    int sum = a[n];
    int m = 0;
    for (int i = 0; i < 2 * n; ++i)
        ps[i + 1] = ps[i] + (cnt[i] - (i != 0? cnt[i - 1]: 0)) * a[i];
    for (int l = 0; l < n; ++l) {
        int r = l + n;
        while (a[r] - a[m] >= a[m] - a[l] + add) {
            ++m;
        }
        handle_res[l] = ps[m] - ps[l + 1] - a[l] * ((m != 0? cnt[m - 1]: 0) - cnt[l]);
    }
}
void get_res_cycle() {
    int n = (int) cycle.size();
    for (int i = 1; i <= 2 * n; ++i)
        a[i] = b[(i - 1) % n];
    for (int i = 1; i <= 2 * n; ++i)
        a[i] += a[i - 1];
    for (int i = 0; i < 2 * n; ++i) {
        cnt[i] = sz[cycle[i % n]];
    }
    for (int i = 1; i < 2 * n; ++i)
        cnt[i] += cnt[i - 1];
    handle(n);
    for (int i = 0; i < n; ++i) {
        res_cycle[cycle[i]] += handle_res[i];
    }
    for (int i = 0; i <= 2 * n; ++i)
        a[i] = a[2 * n] - a[i];
    reverse(a, a + 2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cnt[i] = sz[cycle[n - (i % n) - 1]];
    for (int i = 1; i < 2 * n; ++i)
        cnt[i] += cnt[i - 1];
    memset(handle_res, 0, sizeof handle_res);
    handle(n, 1);
    reverse(handle_res, handle_res + n);
    for (int i = 0; i < n; ++i) {
        res_cycle[cycle[i]] += handle_res[i];
    }
}
int sum_dep[N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(up, -1, sizeof up);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int &u = es[i], &v = et[i], &w = ew[i];
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    find_cycle(0, 0);
    for (int x : cycle) {
        lead[x] = x;
        dfs_down(x, x);
        dfs_up(x, x);
    }
    int sum_all = 0;
    for (int v = 0; v < n; ++v)
        sum_dep[lead[v]] += dep[v], sum_all += dep[v];
    for (int v = 0; v < n; ++v) {
        res[v] += sum_all - sum_dep[lead[v]];
        res[v] += dep[v] * (n - sz[lead[v]]);
    }
    get_res_cycle();
    for (int v = 0; v < n; ++v)
        res[v] += res_cycle[lead[v]];
    for (int v = 0; v < n; ++v) {
        cout << res[v] << ' ';
    }
}