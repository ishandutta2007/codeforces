#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

struct Dsu{
    vector<int> par;
    vector<int> cnt;
    Dsu() {}
    Dsu(int n) {
        par.assign(n, 0);
        cnt.assign(n, 0);
        iota(all(par), 0);
    }
    int getPar(int v) {
        if (v == par[v]) return par[v];
        return par[v] = getPar(par[v]);
    }
    bool connected(int a, int b) {
        return getPar(a) == getPar(b);
    }
    void uni(int a, int b) {
        a = getPar(a);
        b = getPar(b);
        par[a] = b;
        cnt[b] += cnt[a];
    }
};

const int N = 3e5 + 10;
int n, m, q;
vector<int> g[N];

void buildTree() {
    Dsu dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (dsu.connected(u, v)) continue;
        dsu.uni(u, v);
        // cerr << u << " " << v << endl;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

const int LOG = 20;

int jump[N][LOG];
int h[N];

vector<pair<int, int>> fq;

void dfs(int v, int par) {
    jump[v][0] = par;
    for (int i = 1; i < LOG; ++i) {
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    }
    for (auto i : g[v]) {
        if (i == par) continue;
        h[i] = h[v] + 1;
        dfs(i, v);
    }
}

int goUp(int v, int h) {
    for (int i = 0; i < LOG; ++i) {
        if ((h >> i) & 1) {
            v = jump[v][i];
        }
    }
    return v;
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = goUp(u, h[u] - h[v]);
    assert(h[u] == h[v]);
    if (u == v) return u;\
    for (int i = LOG - 1; i >= 0; --i) {
        if (jump[v][i] != jump[u][i]) {
            v = jump[v][i];
            u = jump[u][i];
        }
    }
    assert(jump[v][0] == jump[u][0]);
    return jump[v][0];
}

void buildLCA() {
    dfs(0, 0);
}

int add[N];

void addOne(int u, int v) {
    fq.push_back({u, v});
    // if (u == v) return;
    if (h[u] > h[v]) swap(u, v);
    int l = lca(u, v);
    // cerr << "u = " << u << " v = " << v << " l = " << l << endl;
    if (l == u) {
        add[l]--;
        add[v]++;
    } else {
        assert(l != v);
        add[v]++;
        add[u]++;
        add[l] -= 2;
    }
}

void dfsAdd(int v, int par) {
    for (auto i : g[v]) {
        if (i == par) continue;
        dfsAdd(i, v);
        add[v] += add[i];
    }
}

void go(int u, int v) {
    // if (h[u] > h[v]) swap(u, v);
    int l = lca(u, v);
    vector<int> ans;
    // if (l == u) {
    //     while (v != u) {
    //         ans.push_back(v);
    //         v = jump[v][0];
    //     }
    //     ans.push_back(v);
    // } else {
    while (u != l) {
        ans.push_back(u);
        u = jump[u][0];
    }
    ans.push_back(u);
    int sz = ans.size();
    while (v != l) {
        ans.push_back(v);
        v = jump[v][0];
    }
    reverse(ans.begin() + sz, ans.end());
    // }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}

const int INF = 1e9 + 228;

Dsu fans;

bool used[N];
int dp[N][2];

void dfsDp(int v, int p) {
    // cerr << "v = " << v << endl;
    used[v] = true;
    int cntEdges = 0;
    int sum = 0;
    for (auto i : g[v]) {
        if (i == p) continue;
        if (!fans.connected(i, v)) continue;
        assert(!used[i]);
        // if (used[i]) continue;
        dfsDp(i, v);
        sum += min(dp[i][0], dp[i][1] - 1);
        cntEdges++;
    }
    // cerr << "cntEdges = " << cntEdges << endl;
    if (cntEdges % 2 == 0) {
        dp[v][0] = sum + cntEdges / 2;
        dp[v][1] = INF;
    } else {
        dp[v][1] = sum + cntEdges / 2 + 1;
        // cerr << "sum = " << sum << " cntEdges = " << cntEdges << " 1 = " << 1 << endl;
        // cerr << dp[v][1] << endl;
        dp[v][0] = INF;
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    buildTree();
    buildLCA();
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        addOne(a, b);
    }

    // cerr << "add = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << add[i] << " ";
    // }
    // cerr << endl;
    dfsAdd(0, 0);
    // cerr << "add = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cerr << add[i] << " ";
    // }
    // cerr << endl;

    vector<int> deg(n, 0);
    for (int i = 0; i < n; ++i) {
        add[i] %= 2;
        if (add[i]) {
            deg[i]++;
            deg[jump[i][0]]++;
        }
    }

    // cerr << "deg = " << endl;
    // for (auto i : deg) {
    //     cerr << i << " ";
    // }
    // cerr << endl;

    fans = Dsu(n);
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            fans.cnt[i] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (add[i]) {
            // cerr << "i = " << i << " p = " << jump[i][0] << endl;
            fans.uni(i, jump[i][0]);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (deg[i] != 0 && !used[i]) {
            // cerr << "i = " << i << endl;
            dfsDp(i, i);
            ans += min(dp[i][0], dp[i][1]);
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }

    // for (int i = 0; i < n; ++i) {
    //     int p = fans.getPar(i);
    //     if (used[p]) continue;
    //     used[p] = true;
    //     int x = fans.cnt[p];
    //     if (x == 0) continue;
    //     assert(x > 1);
    //     ans += x - 1;
    // }
    if (ans == 0) {
        cout << "YES\n";
        for (auto [u, v] : fq) {
            go(u, v);
        }
    } else {
        cout << "NO " << ans << '\n';
    }

    return 0;
}