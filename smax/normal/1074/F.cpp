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

struct Node {
    int mn, cnt, lazy = 0, l, r;

    void leaf(int val) {
        mn = val;
        cnt = 1;
    }

    void pull(const Node &a, const Node &b) {
        mn = min(a.mn, b.mn);
        cnt = 0;
        if (mn == a.mn)
            cnt += a.cnt;
        if (mn == b.mn)
            cnt += b.cnt;
    }

    void push(int val) {
        lazy += val;
    }

    void apply() {
        mn += lazy;
        lazy = 0;
    }
};

struct SegmentTree {
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

struct BinaryLift {
    int n, lg;
    vector<int> depth;
    vector<vector<int>> adj, up;

    BinaryLift(int _n) : n(_n), lg(__lg(n - 1) + 1), depth(n), adj(n), up(n, vector<int>(lg, -1)) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init(int r = 0) {
        dfs(r);
        for (int j=1; j<lg; j++)
            for (int i=0; i<n; i++)
                if (up[i][j-1] != -1)
                    up[i][j] = up[up[i][j-1]][j-1];
    }

    void dfs(int u) {
        for (int v : adj[u])
            if (v != up[u][0]) {
                depth[v] = depth[u] + 1;
                up[v][0] = u;
                dfs(v);
            }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        for (int j=lg-1; j>=0; j--)
            if (depth[u] - (1 << j) >= depth[v])
                u = up[u][j];
        if (u == v)
            return u;
        for (int j=lg-1; j>=0; j--)
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        return up[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    int kthAnc(int u, int k) {
        if (k > depth[u])
            return -1;
        for (int j=0; j<lg; j++)
            if (k & (1 << j))
                u = up[u][j];
        return u;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    BinaryLift bl(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        bl.addEdge(u, v);
    }

    int ti = -1;
    vector<int> in(n), out(n);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        in[u] = ++ti;
        for (int v : adj[u])
            if (v != p)
                self(self, v, u);
        out[u] = ti;
    };

    auto anc = [&] (int u, int v) -> bool {
        return in[u] <= in[v] && out[v] <= out[u];
    };

    dfs(dfs, 0, -1);
    bl.init();
    SegmentTree st(n);
    set<pair<int, int>> edges;
    for (int i=0; i<q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (in[u] > in[v])
            swap(u, v);
        int d;
        if (edges.count({u, v})) {
            d = -1;
            edges.erase({u, v});
        } else {
            d = 1;
            edges.emplace(u, v);
        }
        if (anc(u, v)) {
            int w = bl.kthAnc(v, bl.depth[v] - bl.depth[u] - 1);
            if (in[w] < in[v])
                st.update(in[w], in[v] - 1, d);
            if (out[v] + 1 <= out[w])
                st.update(out[v] + 1, out[w], d);
        } else {
            if (in[u] > 0)
                st.update(0, in[u] - 1, d);
            if (out[u] + 1 < in[v])
                st.update(out[u] + 1, in[v] - 1, d);
            if (out[v] + 1 < n)
                st.update(out[v] + 1, n - 1, d);
        }
        cout << (st.st[1].mn == 0 ? st.st[1].cnt : 0) << "\n";
    }

    return 0;
}