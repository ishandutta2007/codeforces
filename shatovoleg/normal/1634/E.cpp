#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

void run() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    vector<int> crd;
    for (auto& line : arr) {
        int l;
        cin >> l;
        line.resize(l);
        cin >> line;
        for (auto x : line) {
            crd.pb(x);
        }
    }
    sort(all(crd));
    crd.resize(unique(all(crd)) - crd.begin());
    for (auto& line : arr) {
        for (auto& x : line) {
            x = int(lower_bound(all(crd), x) - crd.begin());
        }
    }
    const int verts = n + len(crd);
    vector<vector<pii>> g(verts);
    vector<int> used;
    vector<pii> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < len(arr[i]); ++j) {
            auto x = arr[i][j];
            g[i].emplace_back(x + n, len(used));
            g[x + n].emplace_back(i, len(used));
            used.emplace_back(0);
            edges.emplace_back(i, j);
        }
    }
    for (int i = n; i < len(g); ++i) {
        if (len(g[i]) & 1) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> cur_it(verts, 0);
    vector<int> path;
    auto dfs = [&](auto dfs, int v) -> void {
        for (int& i = cur_it[v]; i < len(g[v]); ++i) {
            auto [u, idx] = g[v][i];
            if (used[idx]) continue;
            used[idx] = 1;
            dfs(dfs, u);
            path.pb(idx);
            cmax(--i, 0);
        }
    };
    for (int i = 0; i < verts; ++i) {
        dfs(dfs, i);
    }
    vector<string> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = string(len(arr[i]), 'L');
    }
    for (int i = 0; i < len(path); i += 2) {
        auto [j, k] = edges[path[i]];
        ans[j][k] = 'R';
    }
    cout << "YES\n";
    for (auto& line : ans) {
        cout << line << '\n';
    }
}