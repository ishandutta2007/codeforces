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

// #define TASK "codes"

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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    vector<int> deg(n, 0);
    vector<int> eval(m, 1);
    vector<pii> edges(m);
    {
        int i = 0;
        for (auto& [u, v] : edges) {
            cin >> u >> v;
            --u, --v;
            g[u].pb({v, i});
            g[v].pb({u, i});
            ++i;
        }
    }
    int q;
    cin >> q;
    vector<pii> reqs(q);
    for (auto& [x, y] : reqs) {
        cin >> x >> y;
        ++deg[--x];
        ++deg[--y];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (deg[i] & 1);
    }
    if (cnt) {
        cout << "NO\n";
        cout << (cnt >> 1) << endl;
        return;
    }

    auto bfs = [&g, &eval, &edges, n](int s, int t) {
        vector<ll> dist(n, INF);
        dist[s] = 0;
        deque<int> q;
        q.push_back(s);
        vector<int> prv(n, -1);
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            for (auto& [u, e] : g[v]) {
                if (cmin(dist[u], dist[v] + eval[e])) {
                    if (eval[e]) {
                        q.push_back(u);
                    } else {
                        q.push_front(u);
                    }
                    prv[u] = e;
                }
            }
        }
        vector<int> res;
        while (t != s) {
            int e = prv[t];
            res.pb(e);
            t ^= (edges[e].first ^ edges[e].second);
        }
        reverse(all(res));
        return res;
    };

    cout << "YES\n";
    for (auto& [s, t] : reqs) {
        auto epath = bfs(s, t);
        for (auto& e : epath) {
            eval[e] ^= 1;
        }
        vector<int> path(1, s);
        for (auto& e : epath) {
            path.pb(path.back() ^ edges[e].first ^ edges[e].second);
        }
        cout << len(path) << '\n';
        for (auto& x : path) {
            cout << x + 1 << " ";
        }
        cout << '\n';
    }
}