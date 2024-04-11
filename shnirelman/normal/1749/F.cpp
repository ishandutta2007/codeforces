#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 20;
const int D = 21;

/*
*/

//struct BIT {
//    int n;
//    vector<int> t;
//
//    BIT(int n) : n(n) {
//        t.resize(n, 0);
//    }
//
//    void upd(int i, int x) {
//        for(; i < n; i |= i + 1)
//            t[i] += x;
//    }
//
//    int get(int i) {
//        int res = 0;
//        for(; i >= 0; i = (i & (i + 1)) - 1)
//            res += t[i];
//        return res;
//    }
//};



void upd(int t[N], int i, int x) {
    for(; i < N; i |= i + 1)
        t[i] += x;
}

void upd(int t[N], int l, int r, int x) {
    upd(t, l, x);
    upd(t, r, -x);
}

int get(int t[N], int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

int t[D][N];

vector<int> g[N];
int p[N][LOGN];
int sz[N];
int tin[N], tout[N], T = 0;
int depth[N];

int pos[N];
vector<int> a;

int cur_path = 0;
int path[N];
int root[N];

void dfs1(int v, int par, int deep) {
//    cout << "dfs1 " << v << ' ' << par << ' ' << deep << endl;
    tin[v] = T++;
    depth[v] = deep;

    p[v][0] = par;
    for(int i = 1; i < LOGN; i++)
        p[v][i] = p[p[v][i - 1]][i - 1];

    sz[v] = 1;
    int mx = 0, ind = -1;
    for(int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];

        if(u != par) {
            dfs1(u, v, deep + 1);
            sz[v] += sz[u];
//            cout << "sz " << v << ' ' << sz[v] << ' ' << sz[u] << endl;
            if(ind == -1 || mx < sz[u]) {
                mx = sz[u];
                ind = i;
            }
        }
    }

    if(ind != -1) {
        swap(g[v][0], g[v][ind]);
    }

    tout[v] = T++;
}

void dfs2(int v, int par) {
//    cout << "dfs2 " << v << ' ' << par << endl;
    pos[v] = a.size();
    a.push_back(v);

    int mx = 0, ind = -1;
    for(int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];

        if(u != par) {
            dfs2(u, v);
        }
    }

    int u = g[v][0];

    if(u != par) {
        path[v] = path[u];
        root[path[v]] = v;
    } else {
        path[v] = cur_path++;
        root[path[v]] = v;
    }
}

bool is_anc(int anc, int v) {
    return tin[anc] <= tin[v] && tout[v] <= tout[anc];
}

int lca(int v, int u) {
//    cout << "lca " << v << ' ' << u << " is ";
    if(is_anc(v, u))
        return v;
    else if(is_anc(u, v))
        return u;

    for(int k = LOGN - 1; k >= 0; k--)
        if(!is_anc(p[v][k], u))
            v = p[v][k];
//    cout << p[v][0] << endl;
    return p[v][0];
}

void add_on_path(int anc, int v, int k, int d) {
//    cout << "add_on_path " << anc << ' ' << v << ' ' << k << ' ' << d << endl;
    while(path[v] != path[anc]) {
        upd(t[d], pos[root[path[v]]], pos[v] + 1, k);
        v = p[root[path[v]]][0];
    }

    upd(t[d], pos[anc] + 1, pos[v] + 1, k);
}

int add[N][D];

void change_query(int v, int u, int k, int d) {
    int w = lca(v, u);
//    cout << "change " << v << ' ' << u << " lca = " << w << endl;

    if(v == w)
        swap(v, u);
    if(u == w) {
        if(v != w)
            add_on_path(u, v, k, d);
    } else {
        add_on_path(w, v, k, d);
        add_on_path(w, u, k, d);
    }

    add[w][d] += k;
    for(int i = d - 1; i >= 0 && p[w][0] != w; i--) {
//        cout << "   add " << i << ' ' << w << endl;
        if(i > 0)
            add[w][i - 1] -= k;
        w = p[w][0];
        add[w][i] += k;
    }
}

int get(int v) {
    int res = 0;
    for(int i = 0; i < D; i++) {
        res += get(t[i], pos[v]);
//        cout << "get for " << i << ' ' << res << "  v = " << v << endl;
        for(int j = i; j < D; j++) {
            res += add[v][j];
//            if(add[v][j] != 0)
//                cout << "get for " << i << " for " << j << ' ' << res << endl;
        }

        if(v == p[v][0])
            break;
        v = p[v][0];
    }

    return res;
}

/*
6
1 2
1 3
4 2
5 2
3 6
2
2 4 5 10 2
1 3

6
1 2
1 3
4 2
5 2
3 6
6
2 4 5 10 2
1 3
1 6
2 1 1 10 20
2 6 6 10 20
1 3
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs1(0, 0, 0);
    dfs2(0, 0);

//    cout << "a : ";
//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//    cout << endl;
//
//    cout << "sz : ";
//    for(int i = 0; i < n; i++)
//        cout << sz[i] << ' ';
//    cout << endl;
//
//    cout << "pos : ";
//    for(int i = 0; i < n; i++)
//        cout << pos[i] << ' ';
//    cout << endl;
//
//    cout << "path : ";
//    for(int i = 0; i < n; i++)
//        cout << path[i] << ' ';
//    cout << endl;
//
//    for(int i = 0; i < cur_path; i++)
//        cout << "path " << i << ' ' << root[i] << endl;

//    return 0;

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int v;
            cin >> v;

            cout << get(v - 1) << '\n';
//            cout << endl;
        } else {
            int v, u, k, d;
            cin >> v >> u >> k >> d;

            change_query(v - 1, u - 1, k, d);
        }
    }
}