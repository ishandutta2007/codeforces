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

#define div div228

const int MOD = 998244353;

int add(int a, int b) {
    return ((a + b) % MOD + MOD) % MOD;
} 

int mul(int x, int y) {
    return (ll)x * y % MOD;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

int div(int x, int y) {
    return mul(x, binpow(y, MOD - 2));
}

const int N = 2e5 + 228;

int lp[N];
vector<int> primes;

struct Edge{
    int u, v, x, y;
};

int n;
vector<Edge> g[N];
vector<pair<int, int>> add_val[N];
int cur_val[N];
vector<Edge> edges;
int h[N];
int timer = 0;
int tin[N], tout[N];

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto [i, j, x, y] : g[v]) {
        int to = i ^ j ^ v;
        if (to == p) continue;
        h[to] = h[v] + 1;
        cur_val[to] = mul(cur_val[v], div(x, y));
        dfs(to, v);
    }
    tout[v] = timer - 1;
}

struct SegmentTree{
    int n;
    vector<int> tree;
    vector<int> mod;
    SegmentTree(int _n) : n(_n), tree(4 * n, 0), mod(4 * n, 0) {}
    void push(int v) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
        mod[v] = 0;
    }
    int getVal(int v) {
        return tree[v] + mod[v];
    }
    void add(int v, int tl, int tr, int l, int r, int val) {
        if (tl >= r || tr <= l) return;
        if (tl >= l && tr <= r) {
            mod[v] += val;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            add(v * 2, tl, tm, l, r, val);
            add(v * 2 + 1, tm, tr, l, r, val);
            tree[v] = min(getVal(v * 2), getVal(v * 2 + 1));
        }
    }
    void add(int l, int r, int val) {
        // cerr << "l = " << l << " r = " << r << " val = " << val << endl;
        // for (int i = l; i <= r; ++i) {
        //     tree[i] += val;
        // }
        add(1, 0, n, l, r + 1, val);
    } 
    int get() {
        return getVal(1);
        // return *min_element(all(tree));
    }
};

void solve() {
    cin >> n;
    fill(g, g + n + 10, vector<Edge>());
    fill(h, h + n + 10, 0);
    fill(add_val, add_val + n + 10, vector<pair<int, int>>());
    edges.clear();
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int d = __gcd(x, y);
        x /= d;
        y /= d;
        --u;
        --v;
        swap(x, y);
        g[u].push_back({u, v, x, y});
        g[v].push_back({u, v, y, x});
        edges.push_back({u, v, x, y});
    }
    // cerr << "readOk" << endl;
    timer = 0;
    cur_val[0] = 1;
    dfs(0, 0);
    // for (int i = 0; i < n; ++i) {
    //     cerr << cur_val[i] << " ";
    // }
    // cerr << endl;
    // cerr << div(1, 2) << " " << div(3, 4) << " " << div(9, 16) << endl;
    // cerr << "dfsOk" << endl;
    for (auto [u, v, x, y] : edges) {
        int cur = u;
        swap(x, y);
        if (h[v] > h[u]) {
            cur = v;
            swap(x, y);
        }
        // cerr << "u = " << u << " v = " << v << " cur = " << cur << " x = " << x << " y = " << y << endl;
        while (x > 1) {
            add_val[lp[x]].emplace_back(cur, 1);
            x /= lp[x];
        }
        while (y > 1) {
            add_val[lp[y]].emplace_back(cur, -1);
            y /= lp[y];
        }
    }
    // cerr << "buildOk" << endl;
    SegmentTree tree(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = add(ans, cur_val[i]);
    }
    for (int val = 2; val <= n; ++val) {
        if (lp[val] != val) continue;
        // cerr << "val = " << val << endl;
        for (auto [v, x] : add_val[val]) {
            // cerr << "x = " << x << endl;
            tree.add(tin[v], tout[v], x);
        }
        int cur = tree.get();
        // cerr << "cur = " << cur << endl;
        if (cur < 0) {
            ans = mul(ans, binpow(val, -cur));
        }
        for (auto [v, x] : add_val[val]) {
            tree.add(tin[v], tout[v], -x);
        }
    }
    cout << ans << '\n';
    // cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            lp[i] = i;
            primes.emplace_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= lp[i] && i * primes[j] < N; ++j) {
            lp[primes[j] * i] = primes[j];
        } 
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}