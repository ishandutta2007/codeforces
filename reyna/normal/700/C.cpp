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
const int N = (int) 1e5 + 5, mod = 0;

int n, m, s, t, in[N], mark[N], es[N], cnt, et[N], ew[N], h[N], topar[N], low[N], res = 2e9 + 1, ax = -1, bx = -1;
vector<int> adj[N];
bool smin(int &x, int y) {
    x = min(x, y);
    if (x == y)
        return 1;
    return 0;
}
pair<int, int> find_high(int v, int p, int ep, int eb) {
    h[v] = (p == -1? 1: h[p] + 1);
    in[v] = (v == s);
    pair<int, int> ret = make_pair(2e9, -1);
    low[v] = h[v];
    for (int e : adj[v]) if (e != eb && e != ep) {
        int u = es[e] ^ et[e] ^ v;
        if (!h[u]) {
            ret = min(ret, find_high(u, v, e, eb));
            in[v] += in[u];
            low[v] = min(low[v], low[u]);
        } else {
            low[v] = min(low[v], h[u]);
        }
    }
    if (in[v] && low[v] == h[v] && ep != -1) {
        ret = min(ret, make_pair(ew[ep], ep));
    }
    return ret;
}

void dfs(int v, int p = -1, int ep = -1) {
    mark[v] = 1;
    for (int e : adj[v]) {
        int u = es[e] ^ et[e] ^ v;
        if (ep != e && !mark[u])
          dfs(u, v, e);
    }
    if (ep != -1) {
        memset(h, 0, sizeof h);
        memset(low, 0, sizeof low);
        pair<int, int> hi = find_high(t, -1, -1, ep);
        if (!h[s]) hi.first = 0;
        if (smin(res, hi.first + ew[ep])) {
            ax = ep;
            bx = hi.second;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    --s, --t;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        es[i] = u;
        et[i] = v;
        ew[i] = w;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    dfs(s);
    if (!mark[t]) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    if (res > 2e9) {
        cout << -1 << endl;
        return 0;
    }
    cout << (ax == -1? 0: ew[ax]) + (bx == -1? 0: ew[bx]) << endl;
    cout << (ax != -1) + (bx != -1) << endl;
    if (ax != -1) cout << ax + 1 << ' ';
    if (bx != -1) cout << bx + 1 << ' ';
}