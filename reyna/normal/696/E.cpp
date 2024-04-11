// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define int long long
const int N = (int) 2e5 + 105, mod = 0;

set<pair<int, int>> best[N];
int n, m, q, used, adr[N], h[N], tree_pos[N], st[N], ch[N << 2], f[N], ed[N], sz[N], heavy[N], head[N], tail[N], par[N], last[N];
pair<int, int> mn[N << 2];

void fu(int m, int x) { m += 10;
    while (m > 0)
        f[m] += x, m -= m & -m;
}
int fq(int m, int res = 0) { m += 10;
    while (m < N)
        res += f[m], m += m & -m;
    return res;
}

void push(int v) {
    mn[v << 1 | 0].first += ch[v];
    mn[v << 1 | 1].first += ch[v];
    ch[v << 1 | 0] += ch[v];
    ch[v << 1 | 1] += ch[v];
    ch[v] = 0;
}

void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
    if (i >= e || b >= j)
        return;
    if (i <= b && e <= j) {
        mn[v].first += x;
        ch[v] += x;
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    push(v);
    update(i, j, x, l, b, m);
    update(i, j, x, r, m, e);
    mn[v] = min(mn[l], mn[r]);
}

pair<int, int> query(int i, int j, int v = 1, int b = 0, int e = n) {
    if (i >= e || b >= j)
        return make_pair(1e18, -1);
    if (i <= b && e <= j)
        return mn[v];
    int m = b + e >> 1, l = v << 1, r = l | 1;
    push(v);
    return min(query(i, j, l, b, m), query(i, j, r, m, e));
}

void build(int v = 1, int b = 0, int e = n) {
    if (b + 1 == e) {
        int cur = adr[b];
        if (best[cur].size()) {
            mn[v] = *(best[cur].begin());
            mn[v].second = cur;
            last[cur] = mn[v].first;
        } else {
            mn[v] = make_pair(1e18, -1);
        }
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    build(l, b, m);
    build(r, m, e);
    mn[v] = min(mn[l], mn[r]);
}

vector<int> adj[N];
void dfs_sz(int v, int p = -1) {
    h[v] = (p == -1? 0: h[p] + 1);
    par[v] = p;
    sz[v] = 1;
    st[v] = used++;
    int maxsz = -1;
    for (int u : adj[v])
        if (u != p) {
            dfs_sz(u, v);
            sz[v] += sz[u];
            if (sz[u] > maxsz)
                maxsz = sz[u], heavy[v] = u;
        }
    ed[v] = used;
}

void build_hld() {
    int cur = 0;
    for (int v = 0; v < n; ++v)
        if (par[v] == -1 || heavy[par[v]] != v) {
            for (int u = v; ~u; u = heavy[u])
                adr[cur] = u, tree_pos[u] = cur++, head[u] = v, tail[v] = tree_pos[u];
            for (int u = v; ~u; u = heavy[u])
                tail[u] = tail[v];
        }
    build();
}

int pick(int v) {
    pair<int, int> res = *(best[v].begin());
    int ret = res.first;
    best[v].erase(res);
    int w = (!best[v].size()? 1e18: (*(best[v].begin())).first);
    update(tree_pos[v], tree_pos[v] + 1, w - last[v]);
    last[v] = w;
    return ret;
}

int addition(int v) {
    return fq(st[head[v]]);
}

pair<int, int> get_path(int u, int v) {
    pair<int, int> res = make_pair(1e18, -1);
    while (head[u] != head[v]) {
        if (h[head[u]] > h[head[v]])
            swap(u, v);
        pair<int, int> cur = query(tree_pos[head[v]], tree_pos[v] + 1);
        cur.first += addition(v);
        res = min(res, cur);
        v = par[head[v]];
    }
    if (h[u] > h[v])
        swap(u, v);
    pair<int, int> cur = query(tree_pos[u], tree_pos[v] + 1);
    cur.first += addition(v);
    res = min(res, cur);
    return res;
}

int32_t main() {
    memset(heavy, -1, sizeof heavy);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v; --v;
        best[v].insert(make_pair(i, i));
    }
    dfs_sz(0);
    build_hld();
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int u, v, k;
            cin >> u >> v >> k; --u, --v;
            vector<int> outp;
            while (k--) {
                pair<int, int> res = get_path(u, v);
                if (res.second == -1) break;
                outp.push_back(pick(res.second));
            }
            cout << (int) outp.size() << ' ';
            for (int x : outp)
                cout << x + 1 << ' ';
            cout << '\n';
        } else {
            int v, w;
            cin >> v >> w; --v;
            fu(st[v], -w);
            fu(ed[v] - 1, w);
            update(tree_pos[v], tail[v] + 1, w);
        }
    }

}