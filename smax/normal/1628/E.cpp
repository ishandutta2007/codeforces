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

template<typename T>
struct RMQ {
    vector<vector<T>> spt;

    RMQ(const vector<T> &a) : spt(1, a) {
        int n = (int) a.size();
        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++)
                spt[j][i] = min(spt[j-1][i], spt[j-1][i+(1<<(j-1))]);
        }
    }

    T query(int i, int j) {
        int k = __lg(j - i + 1);
        return min(spt[k][i], spt[k][j-(1<<k)+1]);
    }
};

struct LCA {
    int n;
    vector<int> in, out, depth, path, ret;
    vector<vector<int>> adj;
    RMQ<int> rmq;

    LCA(int _n) : n(_n), in(n, -1), out(n), depth(n), adj(n), rmq({}) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = -1) {
        if (r == -1) {
            for (int u=0; u<n; u++)
                if (in[u] == -1)
                    dfs(u, -1);
        } else {
            dfs(r, -1);
        }
        rmq = RMQ<int>(ret);
    }

    void dfs(int u, int p) {
        in[u] = (int) path.size();
        path.push_back(u);
        ret.push_back(in[u]);
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                path.push_back(u);
                ret.push_back(in[u]);
            }
        out[u] = (int) path.size();
    }

    int lca(int u, int v) {
        if (in[u] > in[v])
            swap(u, v);
        return path[rmq.query(in[u], in[v])];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    bool anc(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }
};

struct SegmentTree {
    struct Node {
        int mn, mx, mnOpen, mxOpen, lazy = -1, l, r;

        void leaf(int val) {
            mn = mx = val;
            mnOpen = INT_MAX;
            mxOpen = INT_MIN;
        }

        void pull(const Node &a, const Node &b) {
            mn = min(a.mn, b.mn);
            mx = max(a.mx, b.mx);
            mnOpen = min(a.mnOpen, b.mnOpen);
            mxOpen = max(a.mxOpen, b.mxOpen);
        }

        void push(int val) {
            lazy = val;
        }

        void apply() {
            if (lazy) {
                mnOpen = mn;
                mxOpen = mx;
            } else {
                mnOpen = INT_MAX;
                mxOpen = INT_MIN;
            }
            lazy = -1;
        }
    };

    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(int _n) : n(_n), a(n), st(4*n) {
        build(1, 0, n-1);
    }

    SegmentTree(const vector<int> &_a) : n((int) _a.size()), a(_a), st(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void push(int p) {
        if (st[p].lazy != -1) {
            if (st[p].l != st[p].r) {
                st[2*p].push(st[p].lazy);
                st[2*p+1].push(st[p].lazy);
            }
            st[p].apply();
        }
    }

    Node query(int p, int i, int j) {
        push(p);
        if (st[p].l == i && st[p].r == j)
            return st[p];
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            return query(2*p, i, j);
        else if (i > m)
            return query(2*p+1, i, j);
        Node ret, ls = query(2*p, i, m), rs = query(2*p+1, m+1, j);
        ret.pull(ls, rs);
        return ret;
    }

    Node query(int i, int j) {
        return query(1, i, j);
    }

    void update(int p, int i, int j, int val) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(val);
            push(p);
            return;
        }
        push(p);
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m) {
            update(2*p, i, j, val);
            push(2*p+1);
        } else if (i > m) {
            push(2*p);
            update(2*p+1, i, j, val);
        } else {
            update(2*p, i, m, val);
            update(2*p+1, m+1, j, val);
        }
        st[p].pull(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int val) {
        update(1, i, j, val);
    }
};

int par[600005];

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<array<int, 3>> edges;
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }

    iota(par, par + 2 * n - 1, 0);
    sort(edges.begin(), edges.end());
    LCA lca(2 * n - 1);
    for (int i=0; i<n-1; i++) {
        auto [w, u, v] = edges[i];
        u = find(u);
        v = find(v);
        par[u] = par[v] = n + i;
        lca.addEdge(n + i, u);
        lca.addEdge(n + i, v);
    }
    lca.init(2 * n - 2);

    SegmentTree st(vector<int>(lca.in.begin(), lca.in.begin() + n));
    for (int i=0; i<q; i++) {
        int t;
        cin >> t;
        if (t == 3) {
            int x;
            cin >> x;
            x--;
            if (st.st[1].mnOpen != INT_MAX) {
                int u = lca.lca(lca.lca(lca.path[st.st[1].mnOpen], lca.path[st.st[1].mxOpen]), x);
                cout << (u < n ? -1 : edges[u-n][0]) << "\n";
            } else {
                cout << "-1\n";
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            st.update(l, r, t == 1);
        }
    }

    return 0;
}