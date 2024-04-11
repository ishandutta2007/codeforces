#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct SegmentTree {
    int n;
    vector<int> a, st, stXor, lazy;

    SegmentTree(int _n) : n(_n), st(4*n), stXor(4*n), lazy(4*n) {}

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n), stXor(4*n), lazy(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = max(st[2*p], st[2*p+1]);
        stXor[p] = stXor[2*p] ^ stXor[2*p+1];
    }

    void push(int p, int l, int r) {
        if (lazy[p]) {
            st[p] = lazy[p];
            if (l != r) {
                lazy[2*p] = lazy[p];
                lazy[2*p+1] = lazy[p];
            }
            lazy[p] = 0;
        }
    }

    int query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (i > r || j < l)
            return 0;
        if (i <= l && r <= j)
            return st[p];
        int m = (l + r) / 2;
        return max(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
    }

    int query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, int val) {
        push(p, l, r);
        if (i > r || j < l)
            return;
        if (i <= l && r <= j) {
            st[p] = val;
            if (l != r) {
                lazy[2*p] = val;
                lazy[2*p+1] = val;
            }
            return;
        }
        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
        st[p] = max(st[2*p], st[2*p+1]);
        stXor[p] = stXor[2*p] ^ stXor[2*p+1];
    }

    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }

    void setEdge(int p, int l, int r, int i, int val) {
        if (l == r) {
            stXor[p] = val;
            return;
        }
        int m = (l + r) / 2;
        push(2*p, l, m);
        push(2*p+1, m+1, r);
        if (i <= m)
            setEdge(2*p, l, m, i, val);
        else
            setEdge(2*p+1, m+1, r, i, val);
        st[p] = max(st[2*p], st[2*p+1]);
        stXor[p] = stXor[2*p] ^ stXor[2*p+1];
    }

    void setEdge(int i, int val) {
        setEdge(1, 0, n-1, i, val);
    }

    int queryXor(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (i > r || j < l)
            return 0;
        if (i <= l && r <= j)
            return stXor[p];
        int m = (l + r) / 2;
        return queryXor(2*p, l, m, i, j) ^ queryXor(2*p+1, m+1, r, i, j);
    }

    int queryXor(int i, int j) {
        return queryXor(1, 0, n-1, i, j);
    }
};

template<bool VAL_IN_EDGES = false>
struct HLD {
    int n, ti;
    vector<int> par, sz, depth, root, pos;
    vector<vector<int>> adj;
    SegmentTree st;

    HLD(int _n) : n(_n), ti(0), par(n, -1), sz(n, 1), depth(n), root(n), pos(n), adj(n), st(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = -1) {
        if (r == -1) {
            for (int u=0; u<n; u++)
                if (par[u] == -1) {
                    dfsSz(u);
                    dfsHld(u);
                }
        } else {
            dfsSz(r);
            dfsHld(r);
        }
    }

    void dfsSz(int u) {
        if (par[u] != -1)
            adj[u].erase(find(adj[u].begin(), adj[u].end(), par[u]));
        for (int &v : adj[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            dfsSz(v);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]])
                swap(v, adj[u][0]);
        }
    }

    void dfsHld(int u) {
        pos[u] = ti++;
        for (int v : adj[u]) {
            root[v] = (v == adj[u][0] ? root[u] : v);
            dfsHld(v);
        }
    }

    template<class B>
    void process(int u, int v, B op) {
        for (; root[u]!=root[v]; u=par[root[u]]) {
            if (depth[root[u]] < depth[root[v]])
                swap(u, v);
            op(pos[root[u]], pos[u]);
        }
        if (depth[u] > depth[v])
            swap(u, v);
        if (pos[u] + VAL_IN_EDGES <= pos[v])
            op(pos[u] + VAL_IN_EDGES, pos[v]);
    }

    // path
    int query(int u, int v) {
        int ret = 0;
        process(u, v, [this, &ret] (int l, int r) {
            ret = max(ret, st.query(l, r));
        });
        return ret;
    }

    void update(int u, int v, int val) {
        process(u, v, [this, &val] (int l, int r) {
            st.update(l, r, val);
        });
    }

    void setEdge(int u, int v, int x) {
        if (par[u] == v) st.setEdge(pos[u], x);
        else st.setEdge(pos[v], x);
    }

    int queryXor(int u, int v) {
        int ret = 0;
        process(u, v, [this, &ret] (int l, int r) {
            ret ^= st.queryXor(l, r);
        });
        return ret;
    }

    // subtree
    int query(int u) {
        return st.query(pos[u] + VAL_IN_EDGES, pos[u] + sz[u] - 1);
    }

    void update(int u, int val) {
        st.update(pos[u] + VAL_IN_EDGES, pos[u] + sz[u] - 1, val);
    }
};

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    HLD<true> hld(n);
    vector<array<int, 3>> edges;
    for (int i=0; i<q; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        if (dsu.unite(u, v))
            hld.addEdge(u, v);
        edges.push_back({u, v, x});
    }

    dsu = DSU(n);
    hld.init();
    for (auto [u, v, x] : edges) {
        if (dsu.unite(u, v)) {
            cout << "YES\n";
            hld.setEdge(u, v, x);
        } else if (hld.query(u, v) == 0 && hld.queryXor(u, v) ^ x) {
            cout << "YES\n";
            hld.update(u, v, 1);
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}