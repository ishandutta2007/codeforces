//
// Created by  on 2019/11/11.
//

//
// Created by  on 2019/11/11.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i,0,n)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template<class T, class U>
void chmin(T &t, const U &u) { if (t > u) t = u; }

template<class T, class U>
void chmax(T &t, const U &u) { if (t < u) t = u; }

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#define MAX_V 100010

int N;
vector<int> G[MAX_V], rG[MAX_V];
vector<int> vs;

bool vis[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to) {
    G[from].pb(to);
    rG[to].pb(from);
}

void dfs(int v) {
    vis[v] = 1;
    for (int to : G[v]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
    vs.pb(v);
}

void rdfs(int v, int k) {
    vis[v] = 1;
    cmp[v] = k;
    for (int to : rG[v]) {
        if (!vis[to]) {
            rdfs(to, k);
        }
    }
}

int scc() {
    memset(vis, 0, sizeof(vis));
    vs.clear();
    rep(v, N) if (!vis[v]) {
        dfs(v);
    }
    memset(vis, 0, sizeof(vis));
    int k = 0;
    reverse(ALL(vs));
    for (int v : vs) {
        if (!vis[v]) {
            rdfs(v, k++);
        }
    }
    return k;
}

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    V<int> u(n);
    rep(i, n) cin >> u[i];
    N = n;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (u[b] == ((u[a] + 1) % h)) {
            add_edge(a, b);
        }
        if (u[a] == ((u[b] + 1) % h)) {
            add_edge(b, a);
        }
    }
    scc();
    VV<int> cp(n);
    V<int> out(n);
    rep(i, n) {
        for (int to : G[i]) {
            if (cmp[i] != cmp[to]) {
                ++out[cmp[i]];
            }
        }
        cp[cmp[i]].pb(i);
    }
    int mx = n + 1;
    V<int> ans;
    rep(i, n) {
        int sz = cp[i].size();
        if (sz > 0 && sz < mx && !out[i]) {
            mx = sz;
            ans = cp[i];
        }
    }

    cout << mx << endl;
    rep(i, mx) cout << ans[i] + 1 << (i == mx - 1 ? '\n' : ' ');

    return 0;
}