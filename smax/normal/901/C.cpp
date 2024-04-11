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
    struct Node {
        int l, r;
        long long ans, lazy;

        void leaf(int val) {
            ans = val;
        }

        void pull(const Node &a, const Node &b) {
            ans = a.ans + b.ans;
        }

        void push(long long val) {
            lazy += val;
        }

        void apply() {
            ans += (r - l + 1) * lazy;
            lazy = 0;
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
        if (st[p].lazy) {
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

    long long query(int i, int j) {
        return query(1, i, j).ans;
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

struct BinaryLift {
    int n, lg;
    vector<int> depth;
    vector<vector<int>> adj, up, mn, mx;

    BinaryLift(int _n) : n(_n), lg(__lg(n - 1) + 1), depth(n), adj(n), up(lg, vector<int>(n, -1)), mn(lg, vector<int>(n)), mx(lg, vector<int>(n)) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = -1) {
        if (r == -1) {
            for (int u=0; u<n; u++)
                if (up[0][u] == -1)
                    dfs(u);
        } else {
            dfs(r);
        }
        for (int i=1; i<lg; i++)
            for (int j=0; j<n; j++)
                if (up[i-1][j] != -1) {
                    up[i][j] = up[i-1][up[i-1][j]];
                    mn[i][j] = min(mn[i-1][j], mn[i-1][up[i-1][j]]);
                    mx[i][j] = max(mx[i-1][j], mx[i-1][up[i-1][j]]);
                }
    }

    void dfs(int u) {
        for (int v : adj[u])
            if (v != up[0][u]) {
                depth[v] = depth[u] + 1;
                up[0][v] = mn[0][v] = mx[0][v] = u;
                dfs(v);
            }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int i=lg-1; i>=0; i--)
            if (depth[u] - (1 << i) >= depth[v])
                u = up[i][u];
        if (u == v)
            return u;
        for (int i=lg-1; i>=0; i--)
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        return up[0][u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int kthAnc(int u, int k) {
        if (k > depth[u])
            return -1;
        for (int i=0; i<lg; i++)
            if (k >> i & 1)
                u = up[i][u];
        return u;
    }

    pair<int, int> query(int u, int v) {
        int retMin = min(u, v), retMax = max(u, v);
        if (depth[u] < depth[v])
            swap(u, v);
        for (int i=lg-1; i>=0; i--)
            if (depth[u] - (1 << i) >= depth[v]) {
                retMin = min(retMin, mn[i][u]);
                retMax = max(retMax, mx[i][u]);
                u = up[i][u];
            }
        if (u == v)
            return {retMin, retMax};
        for (int i=lg-1; i>=0; i--)
            if (up[i][u] != up[i][v]) {
                retMin = min({retMin, mn[i][u], mn[i][v]});
                retMax = max({retMax, mx[i][u], mx[i][v]});
                u = up[i][u];
                v = up[i][v];
            }
        return {min({retMin, mn[0][u], mn[0][v]}), max({retMax, mx[0][u], mx[0][v]})};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<vector<pair<int, int>>> queries(n);
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries[r].emplace_back(l, i);
    }

    BinaryLift lift(n);
    vector<int> depth(n, -1);
    vector<pair<int, int>> extra;

    auto dfs = [&] (auto &self, int u, int p) -> void {
        for (int v : adj[u])
            if (v != p) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    lift.addEdge(u, v);
                    self(self, v, u);
                } else if (depth[v] < depth[u]) {
                    extra.emplace_back(u, v);
                }
            }
    };

    for (int i=0; i<n; i++)
        if (depth[i] == -1) {
            depth[i] = 0;
            dfs(dfs, i, -1);
        }
    lift.init();

    vector<int> constr(n);
    for (auto [u, v] : extra) {
        auto [l, r] = lift.query(u, v);
        constr[r] = max(constr[r], l + 1);
    }

    vector<long long> ret(q);
    SegmentTree st(n);
    int mx = 0;
    for (int r=0; r<n; r++) {
        mx = max(mx, constr[r]);
        if (mx <= r)
            st.update(mx, r, 1);
        for (auto [l, i] : queries[r])
            ret[i] = st.query(l, r);
    }

    for (long long x : ret)
        cout << x << "\n";

    return 0;
}