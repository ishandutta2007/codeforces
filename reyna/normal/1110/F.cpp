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
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;
#define int long long
const int N = (int) 5e5 + 5, mod = (int) 9;
int n, seg[N << 2], ch[N << 2];
int sz[N], st[N], ed[N], res[N], ql[N], qr[N], qv[N];
int h[N];
vector<pair<int, int>> adj[N];
vector<int> queries[N];
void build(int v = 1, int b = 0, int e = n) {
    if (b + 1 == e) {
        if (adj[b].size() == 0) {
            seg[v] = h[b];
        } else {
            seg[v] = 1e18;
        }
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    build(l, b, m);
    build(r, m, e);
    seg[v] = min(seg[l], seg[r]);
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
    if (i >= e || b >= j) return;
    if (i <= b && e <= j) {
        seg[v] += x;
        ch[v] += x;
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    update(i, j, x, l, b, m);
    update(i, j, x, r, m, e);
    seg[v] = min(seg[l], seg[r]) + ch[v];
}
int query(int i, int j, int v = 1, int b = 0, int e = n) {
    if (i >= e || b >= j) return 1e18;
    if (i <= b && e <= j) return seg[v];
    int m = b + e >> 1, l = v << 1, r = l | 1;
    return min(query(i, j, l, b, m), query(i, j, r, m, e)) + ch[v];
}
void dfs_init(int v, int p = -1) {
    for (auto e : adj[v]) {
        int w = e.second, u = e.first;
        h[u] = h[v] + w;
        dfs_init(u, v);
        sz[v] += sz[u];
    }
    sz[v] += 1;
    st[v] = v;
    ed[v] = st[v] + sz[v];
}
void dfs_res(int v, int p = -1) {
    for (int j : queries[v]) {
        int xl = ql[j], xr = qr[j];
        res[j] = query(xl, xr);
    }
    for (auto e : adj[v]) {
        int u = e.first, w = e.second;
        update(0, n, w);
        update(st[u], ed[u], -2 * w);
        dfs_res(u, v);
        update(0, n, -w);
        update(st[u], ed[u], 2 * w);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> n >> q;
    for (int j = 1; j < n; ++j) {
        int p, w;
        cin >> p >> w;
        --p;
        adj[p].push_back(mp(j, w));
    }
    dfs_init(0);
    build();
    for (int j = 0; j < q; ++j) {
        cin >> qv[j] >> ql[j] >> qr[j];
        --ql[j];
        --qv[j];
        queries[qv[j]].push_back(j);
    }
    dfs_res(0);
    for (int j = 0; j < q; ++j)
        cout << res[j] << '\n';
}