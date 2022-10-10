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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAX = 3e5 + 5;
const int SZ = 550;

struct RMQ {
    vector<int> a;
    vector<vector<int>> spt;

    void init(int n, int *_a) {
        a.resize(n);
        spt.assign(1, vector<int>(n));
        for (int i=0; i<n; i++) {
            a[i] = _a[i];
            spt[0][i] = i;
        }

        for (int j=1; 1<<j<=n; j++) {
            spt.emplace_back(n - (1 << j) + 1);
            for (int i=0; i+(1<<j)<=n; i++) {
                if (a[spt[j-1][i]] < a[spt[j-1][i+(1<<(j-1))]])
                    spt[j][i] = spt[j-1][i];
                else
                    spt[j][i] = spt[j-1][i+(1<<(j-1))];
            }
        }
    }

    int query(int i, int j) {
        int k = 31 - __builtin_clz(j - i + 1);
        if (a[spt[k][i]] < a[spt[k][j-(1<<k)+1]])
            return spt[k][i];
        else
            return spt[k][j-(1<<k)+1];
    }
};

namespace LCA {
    int idx, ti[MAX], node[2*MAX], depth[2*MAX];
    vector<int> adj[MAX];
    RMQ rmq;

    void dfs(int u, int p, int d) {
        ti[u] = idx;
        node[idx] = u;
        depth[idx++] = d;
        for (int v : adj[u])
            if (v != p) {
                dfs(v, u, d + 1);
                node[idx] = u;
                depth[idx++] = d;
            }
    }

    int lca(int u, int v) {
        if (ti[u] > ti[v])
            swap(u, v);
        return node[rmq.query(ti[u], ti[v])];
    }

    int dist(int u, int v) {
        return depth[ti[u]] + depth[ti[v]] - 2 * depth[ti[lca(u, v)]];
    }

    void preprocess() {
        idx = 0;
        dfs(0, -1, 0);
        rmq.init(idx, depth);
    }
};

struct Query {
    int l, r, ql, qr, w, idx;

    bool operator < (const Query &other) const {
        if (ql / SZ == other.ql / SZ) {
            if (qr == other.qr)
                return idx < other.idx;
            return (ql / SZ % 2 ? qr > other.qr : qr < other.qr);
        }
        return ql / SZ < other.ql / SZ;
    }
};

int a[MAX], in[MAX], out[MAX], block[SZ], parity[MAX], ret[MAX];
Query queries[MAX];
vector<int> preorder;

void dfs(int u, int p) {
    in[u] = (int) preorder.size();
    preorder.push_back(u);
    for (int v : LCA::adj[u])
        if (v != p)
            dfs(v, u);
    out[u] = (int) preorder.size();
    preorder.push_back(u);
}

void toggle(int i) {
    int c = a[preorder[i]];
    parity[c] ^= 1;
    if (parity[c])
        block[c / SZ]++;
    else
        block[c / SZ]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        LCA::adj[x].push_back(y);
        LCA::adj[y].push_back(x);
    }

    dfs(0, -1);
    LCA::preprocess();

    for (int i=0; i<q; i++) {
        int u, v;
        cin >> u >> v >> queries[i].l >> queries[i].r;
        u--, v--;
        if (in[u] > in[v])
            swap(u, v);
        queries[i].w = LCA::lca(u, v);
        if (queries[i].w == u || queries[i].w == v) {
            queries[i].ql = in[u];
            queries[i].qr = in[v];
            queries[i].w = -1;
        } else {
            queries[i].ql = out[u];
            queries[i].qr = in[v];
            queries[i].w = in[queries[i].w];
        }
        queries[i].idx = i;
    }

    sort(queries, queries + q);
    int moLeft = 0, moRight = -1;
    for (int i=0; i<q; i++) {
        while (moLeft > queries[i].ql)
            toggle(--moLeft);
        while (moRight < queries[i].qr)
            toggle(++moRight);
        while (moLeft < queries[i].ql)
            toggle(moLeft++);
        while (moRight > queries[i].qr)
            toggle(moRight--);
        if (queries[i].w != -1)
            toggle(queries[i].w);
        ret[queries[i].idx] = -1;
        int cl = queries[i].l / SZ, cr = queries[i].r / SZ;
        if (cl == cr) {
            for (int c=queries[i].l; c<=queries[i].r; c++)
                if (parity[c]) {
                    ret[queries[i].idx] = c;
                    break;
                }
        } else {
            for (int c=queries[i].l; c<(cl+1)*SZ; c++)
                if (parity[c]) {
                    ret[queries[i].idx] = c;
                    break;
                }
            if (ret[queries[i].idx] == -1) {
                for (int j=cl+1; j<cr; j++)
                    if (block[j]) {
                        for (int c=j*SZ; c<(j+1)*SZ; c++)
                            if (parity[c]) {
                                ret[queries[i].idx] = c;
                                break;
                            }
                        break;
                    }
                if (ret[queries[i].idx] == -1) {
                    for (int c=cr*SZ; c<=queries[i].r; c++)
                        if (parity[c]) {
                            ret[queries[i].idx] = c;
                            break;
                        }
                }
            }
        }
        if (queries[i].w != -1)
            toggle(queries[i].w);
    }

    for (int i=0; i<q; i++)
        cout << ret[i] << "\n";

    return 0;
}