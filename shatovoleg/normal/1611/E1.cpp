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

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

vector<int> bfs(const vector<vector<int>>& g, const vector<int>& starts) {
    const int n = len(g);
    vector<int> dist(n, INF);
    queue<int> q;
    for (auto& x : starts) {
        q.push(x);
        dist[x] = 1;
    }
    while (len(q)) {
        int v = q.front();
        q.pop();
        for (auto& x : g[v]) {
            if (cmin(dist[x], dist[v] + 1)) {
                q.push(x);
            }
        }
    }
    return dist;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> friends(k);
    for (auto& x : friends) {
        cin >> x;
        --x;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> d1 = bfs(g, {0}), d2 = bfs(g, friends);
    for (int i = 1; i < n; ++i) {
        if (len(g[i]) == 1 && d1[i] < d2[i]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}