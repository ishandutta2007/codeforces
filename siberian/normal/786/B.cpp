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

struct Edge{
    int to, cost;
};

const int N = 1e6 + 10;
int n, m;
int s;
vector<Edge> g[N];
set<pair<ll, int>> q;
ll dist[N];

void build(int v, int tl, int tr) {
    for (int i = tl; i < tr; ++i) {
        g[v + n].push_back({i, 0});
        g[i].push_back({v + 4 * n + n, 0});
    }
    if (tl == tr - 1) return;
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm, tr);
}

void addFrom(int v, int tl, int tr, int l, int r, int from, int cost) {
    if (tl >= r || tr <= l) return;
    if (tl >= l && tr <= r) {
        g[from].push_back({v + n, cost});
    } else {
        int tm = (tl + tr) / 2;
        addFrom(v * 2, tl, tm, l, r, from, cost);
        addFrom(v * 2 + 1, tm, tr, l, r, from, cost);
    }
}

void addTo(int v, int tl, int tr, int l, int r, int to, int cost) {
    if (tl >= r || tr <= l) return;
    if (tl >= l && tr <= r) {
        g[v + 4 * n + n].push_back({to, cost});
    } else {
        int tm = (tl + tr) / 2;
        addTo(v * 2, tl, tm, l, r, to, cost);
        addTo(v * 2 + 1, tm, tr, l, r, to, cost);
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m >> s;
    --s;
    build(1, 0, n);
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int from, to, cost;
            cin >> from >> to >> cost;
            --from;
            --to;
            g[from].push_back({to, cost});
        } else if (t == 2) {
            int v, l, r, cost;
            cin >> v >> l >> r >> cost;
            --v;
            --l;
            --r;
            addFrom(1, 0, n, l, r + 1, v, cost);
        } else if (t == 3) {
            int v, l, r, cost;
            cin >> v >> l >> r >> cost;
            --v;
            --l;
            --r;
            addTo(1, 0, n, l, r + 1, v, cost);
        } else {
            assert(false);
        }
    }
    fill(dist, dist + N, LONG_LONG_MAX);
    dist[s] = 0;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, cost] : g[v]) {
            ll ncost = cost + dist[v];
            if (ncost >= dist[to]) continue;
            q.erase({dist[to], to});
            dist[to] = ncost;
            q.insert({dist[to], to});
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << ' ';
        if (dist[i] == LONG_LONG_MAX) {
            cout << "-1";
        } else {
            cout << dist[i];
        }
    }
    cout << '\n';
    return 0;
}