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

struct SegmentTree {
    int n;
    vector<bool> st;
    vector<int> lazy;

    SegmentTree(int _n) : n(_n), st(4*n), lazy(4*n, -1) {}

    void push(int p, int l, int r) {
        if (lazy[p] != -1) {
            st[p] = lazy[p];
            if (l != r) {
                lazy[2*p] = lazy[p];
                lazy[2*p+1] = lazy[p];
            }
            lazy[p] = -1;
        }
    }

    bool query(int p, int l, int r, int i, int j) {
        push(p, l, r);

        if (i > r || j < l)
            return true;
        if (i <= l && r <= j)
            return st[p];

        int m = (l + r) / 2;
        return query(2*p, l, m, i, j) && query(2*p+1, m+1, r, i, j);
    }

    bool query(int i, int j) {
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
        st[p] = st[2*p] && st[2*p+1];
    }

    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }
};

int ti = 0, in[500005], out[500005], par[500005];
vector<int> adj[500005];

void dfs(int u) {
    in[u] = ti++;
    for (int v : adj[u])
        if (v != par[u]) {
            par[v] = u;
            dfs(v);
        }
    out[u] = ti;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    par[0] = -1;
    dfs(0);
    SegmentTree st(n);

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int c, v;
        cin >> c >> v;
        v--;
        if (c == 1) {
            if (!st.query(in[v], out[v] - 1)) {
                if (par[v] != -1)
                    st.update(in[par[v]], in[par[v]], 0);
                st.update(in[v], out[v] - 1, 1);
            }
        } else if (c == 2)
            st.update(in[v], in[v], 0);
        else
            cout << st.query(in[v], out[v] - 1) << "\n";
    }

    return 0;
}