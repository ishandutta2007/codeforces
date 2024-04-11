#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct RangeTree {
    int al, ar;
    ll rsum, lazy;
    RangeTree *left, *right;
    void combine() {
        rsum = left->rsum + right->rsum;
    }
    void propagate() {
        if (lazy != 0) {
            rsum += (ar - al + 1) * lazy;
            if (left != nullptr) {
                left->lazy += lazy;
                right->lazy += lazy;
            }
            lazy = 0;
        }
    }
    RangeTree() {}
    RangeTree(int i, int j) : al(i), ar(j), rsum(0), lazy(0), left(nullptr), right(nullptr) {
        if (i != j) {
            int k = (i + j) / 2;
            left = new RangeTree(i, k);
            right = new RangeTree(k + 1, j);
        }
    }
    void addRange(int i, int j, ll v) {
        // printf("addRange %d %d %lld\n", i, j, v);
        propagate();
        if (ar < i || j < al) return;
        else if (i <= al && ar <= j) {
            // printf("stop at %d %d\n", al, ar);
            lazy += v;
            propagate();
        } else {
            left->addRange(i, j, v); right->addRange(i, j, v);
            combine();
        }
    }
    ll qRange(int i, int j) {
        propagate();
        if (ar < i || j < al) return 0;
        else if (i <= al && ar <= j) return rsum;
        else return left->qRange(i, j) + right->qRange(i, j);
    }
};

struct TreeManager {
    vector<vector<int>> tree;
    vector<vector<int>> jtable;
    vector<int> st, ed, depth;
    vector<ll> values;
    RangeTree proot;
    TreeManager() {}
    void DFS(int v, int p, int &t, int cLevel) {
        jtable[0][v] = p;
        st[v] = ed[v] = t;
        t++;
        depth[v] = cLevel;
        for (int nxt : tree[v]) {
            if (nxt == p) continue;
            DFS(nxt, v, t, cLevel + 1);
            ed[v] = ed[nxt];
        }
    }
    TreeManager(vector<vector<int>> &tree, vector<ll> &vals) : 
        tree(tree), jtable(20, vector<int>(tree.size(), -1)), proot(0, int(tree.size()) - 1), 
        st(tree.size()), ed(tree.size()), depth(tree.size()), values(vals) {
        
        int travTime = 0;
        DFS(0, -1, travTime, 0);
        for (int i = 0; i < tree.size(); ++i) {
            proot.addRange(st[i], ed[i], vals[i]);
        }
        for (int l = 1; l < 20; ++l) {
            for (int i = 0; i < tree.size(); ++i) {
                if (jtable[l-1][i] != -1) jtable[l][i] = jtable[l-1][jtable[l-1][i]];
            }
        }
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        if (depth[u] > depth[v]) {
            for (int js = 19; js >= 0; --js) 
                if (jtable[js][u] != -1 && depth[jtable[js][u]] >= depth[v]) u = jtable[js][u];
        }
        if (u == v) return u;
        for (int js = 19; js >= 0; --js) {
            if (jtable[js][u] != -1 && jtable[js][u] != jtable[js][v]) {
                u = jtable[js][u]; v = jtable[js][v];
            }
        }
        return jtable[0][u];
    }
    void setNumber(int i, ll v) {
        ll delta = v - values[i];
        proot.addRange(st[i], ed[i], delta);
        values[i] += delta;
    }
    ll pathQuery(int i, int j) {
        int k = LCA(i, j);
        // printf("%d %d lca %d\n", i, j, k);
        ll ipath = proot.qRange(st[i], st[i]), jpath = proot.qRange(st[j], st[j]),
            kpath = proot.qRange(st[k], st[k]);
        // printf("psums %lld %lld %lld\n", ipath, jpath, kpath);
        return 2 * ipath + 2 * jpath - 4 * kpath + 2 * values[k] - values[i] - values[j];
    }
};

int main() {
    int n, q; scanf("%d %d", &n, &q);
    vector<ll> illusion(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &illusion[i]);
    for (int i = 0; i < n; ++i) illusion[i] = abs(illusion[i]);
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        tree[--x].push_back(--y);
        tree[y].push_back(x);
    }
    TreeManager tm(tree, illusion);
    while (q--) {
        int qt, u, p; scanf("%d %d %d", &qt, &u, &p); --u;
        if (qt == 1) {
            p = abs(p);
            tm.setNumber(u, p);
        } else {
            --p;
            printf("%lld\n", tm.pathQuery(u, p));
        }
    }
}