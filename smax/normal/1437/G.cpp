#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int MAX = 3e5 + 5;
const int ALPHA = 26;

struct SegmentTree {
    int n;
    vector<int> a, st, lazy;

    SegmentTree(int _n) : n(_n), st(4*n, -1), lazy(4*n) {}

    SegmentTree(const vector<int> &_a) : n(_a.size()), a(_a), st(4*n), lazy(4*n) {
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p] += a[l];
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p] = st[2*p] + st[2*p+1];
    }

    void push(int p, int l, int r) {
        if (lazy[p]) {
            st[p] += (r - l + 1) * lazy[p];
            if (l != r) {
                lazy[2*p] += lazy[p];
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    int query(int p, int l, int r, int i, int j) {
        push(p, l, r);

        if (i > r || j < l)
            return -1;
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
            st[p] += (r - l + 1) * val;
            if (l != r) {
                lazy[2*p] += val;
                lazy[2*p+1] += val;
            }
            return;
        }

        int m = (l + r) / 2;
        update(2*p, l, m, i, j, val);
        update(2*p+1, m+1, r, i, j, val);
        st[p] = st[2*p] + st[2*p+1];
    }

    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }

    void pointUpdate(int p, int l, int r, int i, int val) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            pointUpdate(2*p, l, m, i, val);
        else
            pointUpdate(2*p+1, m+1, r, i, val);
        st[p] = max(st[2*p], st[2*p+1]);
    }

    void pointUpdate(int i, int val) {
        pointUpdate(1, 0, n-1, i, val);
    }
};

template<bool VAL_IN_EDGES>
struct HLD {
    int ti;
    vector<int> par, sz, depth, root, pos;
    vector<vector<int>> adj;
    SegmentTree st;

    HLD(int n) : ti(0), par(n, -1), sz(n, 1), depth(n), root(n), pos(n), adj(n), st(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void init() {
        dfsSz(0);
        dfsHld(0);
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
        op(pos[u] + VAL_IN_EDGES, pos[v]);
    }

    // path
    int query(int u, int v) {
        int ret = -1;
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

    // subtree
    int query(int u) {
        return st.query(pos[u] + VAL_IN_EDGES, pos[u] + sz[u] - 1);
    }

    void update(int u, int val) {
        st.update(pos[u] + VAL_IN_EDGES, pos[u] + sz[u] - 1, val);
    }

    void pointUpdate(int u, int val) {
        st.pointUpdate(pos[u], val);
    }
};

int id = 1, trie[MAX][ALPHA], link[MAX], node[MAX];

void add(const string &s, int i) {
    int u = 0;
    for (char c : s) {
        if (!trie[u][c-'a'])
            u = trie[u][c-'a'] = id++;
        else
            u = trie[u][c-'a'];
    }
    node[i] = u;
}

void gen(HLD<false> &hld) {
    link[0] = -1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j=0; j<ALPHA; j++) {
            int v = trie[u][j];
            if (v) {
                link[v] = (link[u] == -1 ? 0 : trie[link[u]][j]);
                q.push(v);
                hld.addEdge(link[v], v);
            } else if (u) {
                trie[u][j] = trie[link[u]][j];
            }
        }
    }
}

int val[MAX];
multiset<int> st[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        add(s, i);
    }

    HLD<false> hld(id);
    gen(hld);
    hld.init();
    for (int i=0; i<n; i++) {
        hld.pointUpdate(node[i], 0);
        st[node[i]].insert(0);
    }

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            st[node[i]].erase(st[node[i]].find(val[i]));
            st[node[i]].insert(x);
            val[i] = x;
            hld.pointUpdate(node[i], *st[node[i]].rbegin());
        } else {
            string q;
            cin >> q;
            int u = 0, ret = -1;
            for (char c : q) {
                u = trie[u][c-'a'];
                ret = max(ret, hld.query(0, u));
            }
            cout << ret << "\n";
        }
    }

    return 0;
}