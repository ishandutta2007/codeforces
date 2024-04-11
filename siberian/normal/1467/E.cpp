#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
int n;
vector<int> g[N];
int a[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

vector<int> comps[N];
int colors[N];
int topColor = 0;

int getColor(int x) {
    return lower_bound(colors, colors + topColor, x) - colors;
}

void build() {
    for (int i = 0; i < n; ++i) {
        colors[i] = a[i];
    }
    sort(colors, colors + n);
    topColor = unique(colors, colors + n) - colors;
    for (int i = 0; i < n; ++i) {
        a[i] = getColor(a[i]);
        comps[a[i]].push_back(i);
    }
}

const int LOG = 20;
int h[N];
int jumps[N][LOG];
int tin[N], tout[N], timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    jumps[v][0] = p;
    for (int i = 1; i < LOG; ++i) {
        jumps[v][i] = jumps[jumps[v][i - 1]][i - 1];
    }
    for (auto i : g[v]) {
        if (i == p) continue;
        h[i] = h[v] + 1;
        dfs(i, v); 
    }
    tout[v] = timer++;
}

bool isUpper(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int goUp(int v, int h) {
    for (int bit = 0; bit < LOG; ++bit) {
        if ((h >> bit) & 1) {
            v = jumps[v][bit];
        }
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = goUp(v, h[v] - h[u]);
    if (v == u) return v;
    for (int bit = LOG - 1; bit >= 0; --bit) {
        if (jumps[v][bit] != jumps[u][bit]) {
            v = jumps[v][bit];
            u = jumps[u][bit];
        }
    }
    assert(jumps[v][0] == jumps[u][0]);
    return jumps[v][0];
}

int add[N];

void dfsAns(int v, int p) {
    for (auto i : g[v]) {
        if (i == p) continue;
        add[i] += add[v]; 
        dfsAns(i, v);
    }
}

int ans;

void no() {
    cout << "0\n";
    exit(0);
}

void solve(int color) {
    vector<int>& a = comps[color];
    assert(!a.empty());
    if (a.size() == 1) {
        ++add[0];
        return;
    }
    sort(all(a), [&] (int v, int u) {
        return tin[v] < tin[u];
    });
    // cerr << "a = " << endl;
    // for (auto i : a) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
    int l = a[0];
    for (auto v : a) {
        l = lca(l, v);
    }
    // cerr << "lca = " << l << endl;
    bool have = false;
    for (auto v : a) {
        if (v == l) {
            have = true;
        }
    } 
    // cerr << "have = " << have << endl;
    if (have) {
        assert(l == a[0]);
        int x = goUp(a[1], h[a[1]] - h[l] - 1);
        for (int i = 2; i < a.size(); ++i) {
            if (goUp(a[i], h[a[i]] - h[l] - 1) != x) {
                no();
            }
            if (isUpper(a[i], a[i - 1]) || isUpper(a[i - 1], a[i])) {
                no();
            }
        }
        // cerr << "x = " << x << endl;
        ++add[x];
        for (int i = 1; i < a.size(); ++i) {
            --add[a[i]];
        }
    } else {
        ++add[0];
        for (int i = 1; i < a.size(); ++i) {
            if (isUpper(a[i], a[i - 1]) || isUpper(a[i - 1], a[i])) {
                no();
            }
        }
        for (auto v : a) {
            --add[v];
        }
    }
}

void run() {
    build();
    dfs(0, 0);
    for (int i = 0; i < topColor; ++i) {
        solve(i);
    }
    ans = 0;
    dfsAns(0, 0);
    for (int i = 0; i < n; ++i) {
        if (add[i] == topColor) {
            ++ans;
        }
    }
}

void write() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}


/*
3
1 2 1 
1 2
2 3
ans = 1

*/