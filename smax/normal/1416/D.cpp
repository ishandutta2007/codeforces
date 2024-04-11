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

template<int SZ>
struct DSU {
    int id, par[SZ];
    vector<int> adj[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            adj[i].clear();
        }
        id = n;
    }

    int findRoot(int u) {
        if (u != par[u])
            par[u] = findRoot(par[u]);
        return par[u];
    }

    void unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u != v) {
            par[u] = par[v] = par[id] = id;
            adj[id].push_back(u);
            adj[id].push_back(v);
            id++;
        }
    }
};

template<int SZ>
struct SegmentTree {
    int n;
    pair<int, int> st[2*SZ];

    void build(vector<int> &a) {
        n = a.size();
        for (int i=0; i<n; i++)
            st[i+n] = {a[i], i};
        for (int i=n-1; i>0; i--)
            st[i] = max(st[i<<1], st[i<<1|1]);
    }

    pair<int, int> query(int l, int r) {
        pair<int, int> ret(0, 0);
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = max(ret, st[l++]);
            if (r&1) ret = max(ret, st[--r]);
        }
        return ret;
    }

    void update(int p, int val) {
        for (st[p+=n].first=val; p>1; p>>=1)
            st[p>>1] = max(st[p], st[p^1]);
    }
};

int n, a[300005], b[300005], p[400005], in[400005], out[400005];
bool rem[300005], vis[400005];
DSU<400005> ds;
SegmentTree<400005> st;
vector<int> preorder;

void dfs(int u) {
    in[u] = preorder.size();
    preorder.push_back(p[u]);
    vis[u] = true;
    for (int v : ds.adj[u])
        dfs(v);
    out[u] = preorder.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, q;
    cin >> n >> m >> q;
    for (int i=0; i<n; i++)
        cin >> p[i];
    for (int i=0; i<m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    vector<pair<int, int>> queries;
    for (int i=0; i<q; i++) {
        int t, v;
        cin >> t >> v;
        v--;
        queries.emplace_back(t, v);
        if (t == 2)
            rem[v] = true;
    }
    for (int i=0; i<m; i++)
        if (!rem[i])
            queries.emplace_back(2, i);

    ds.init(n);
    reverse(queries.begin(), queries.end());
    for (auto &[t, v] : queries) {
        if (t == 1)
            v = ds.findRoot(v);
        else
            ds.unite(a[v], b[v]);
    }

    for (int i=0; i<n; i++)
        if (!vis[ds.findRoot(i)])
            dfs(ds.findRoot(i));
    st.build(preorder);
    reverse(queries.begin(), queries.end());
    for (auto [t, v] : queries) {
        if (t == 1) {
            auto ret = st.query(in[v], out[v]);
            cout << ret.first << "\n";
            if (ret.first > 0)
                st.update(ret.second, 0);
        }
    }

    return 0;
}