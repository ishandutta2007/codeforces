#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
struct segtree{
    int sz;
    vector<int> tree;
    segtree(int n) {
        sz = 1;
        while (sz <= n)
            sz *= 2;
        tree.assign(sz * 2, 0);
    }
    void add(int v, int x) {
        v += sz;
        tree[v] += x;
        while (v > 1) {
            v /= 2;
            tree[v] += x;
        }
    }
    int get(int l, int r) {
        int res = 0;
        l += sz;
        r += sz;
        while (l < r) {
            if (l & 1) {
                res += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                res += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        if (l == r) {
            res += tree[l];
        }
        return res;
    }
    void add(int l, int r, int x) { // add [l, r)
        add(l, x);
        add(r, -x);
    }
    int get(int v) {
        return get(0, v);
    }
};
int t = 0;
vector<int> par;
vector<int32_t> sz;
vector<pair<int32_t, int>> big;
vector<vector<int32_t>> expect;
vector<vector<int32_t>> g;
vector<pair<int32_t, int32_t>> tinout;
vector<int32_t> segt, numinsegt;
void dfs(int v, int p) {
    par[v] = p;
    sz[v] = 1;
    tinout[v].first = t++;
    numinsegt[v] = segt.size();
    segt.push_back(v);
    for (auto i : g[v]) {
        if (i != p) {
            dfs(i, v);
            sz[v] += sz[i];
        }
    }
    tinout[v].second = t;
}
int dfssz(int v, int p) {
    int res = 1;
    for (auto i : g[v]) {
        if (i != p)
            res += dfssz(i, v);
    }
    return res;
}
int k = 370;
void dfsch(int v, int p, int sz, int bv) {
    expect[bv][v] = sz;
    for (auto i : g[v]) {
        if (i != p)
            dfsch(i, v, sz, bv);
    }
}
void makebig(int v) {
    int n = g.size();
    expect[v].assign(n, 0);
    expect[v][v] = n;
    for (auto i : g[v]) {
        dfsch(i, v, n - dfssz(i, v), v);
    }
}
int mod = 998244353;
int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pow(x, mod - 2);
}
segtree globsg(1);
int allval = 0;
void ddd(int v, int d) {
    for (auto &[u, vl] : big) {
        if (v == u) {
            vl += d;
            vl %= mod;
            return;
        }
    }
    int n = g.size();
    int vvl = sz[v] * d;
    vvl %= mod;
    globsg.add(tinout[v].first, tinout[v].first + 1, (n * d - vvl) % mod);
    allval += vvl;
    for (auto i : g[v]) {
        if (i != par[v])
            globsg.add(tinout[i].first, tinout[i].second, ((n - sz[i]) * d - vvl) % mod);
    }
}
int vl(int v) {
    int res = 0;
    for (auto [u, val] : big) {
        res += expect[u][v] * val;
        res %= mod;
    }
    res += allval;
    res += globsg.get(tinout[v].first);
    res %= mod;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    par.assign(n, 0);
    sz.assign(n, 0);
    int invn = inv(n);
    expect.assign(n, {});
    g.assign(n, {});
    tinout.assign(n, {});
    numinsegt.assign(n, {});
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    segtree sg(n);
    globsg = sg;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= k) {
            big.push_back({i, 0});
            makebig(i);
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, d;
            cin >> v >> d;
            ddd(v-1, d);
        } else {
            int v;
            cin >> v;
            cout << ((vl(v-1) * invn) % mod + mod) % mod << '\n';
        }
    }
}