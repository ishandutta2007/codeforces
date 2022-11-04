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

struct DSU {
    vector<int> l, s;

    DSU(int n) : l(n), s(n) { reset(); }

    int GetRoot(int v) {
        if (l[v] == v) return v;
        return l[v] = GetRoot(l[v]);
    }

    bool Union(int u, int v) {
        u = GetRoot(u);
        v = GetRoot(v);
        if (u == v) return false;
        if (s[u] > s[v]) {
            swap(u, v);
        }
        l[u] = v;
        s[v] += s[u];
        return true;
    }

    void reset() {
        iota(all(l), 0);
        fill(all(s), 1);
    }
};

vector<ll> GetSpanningTreeEdges(int n, vector<array<int, 3>>& edges, int x) {
    sort(all(edges), [x](array<int, 3> a, array<int, 3> b) {
        return mp(abs(a[2] - x), a[2]) < mp(abs(b[2] - x), b[2]);
    });
    static DSU d(n);
    vector<ll> ans;
    ans.reserve(n - 1);
    for (auto [u, v, w] : edges) {
        if (d.Union(u, v)) {
            ans.pb(w);
        }
    }
    d.reset();
    return ans;
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[i] = {u, v, w};
    }
    vector<int> points;
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            int sm = edges[i][2] + edges[j][2];
            points.pb(sm / 2);
        }
    }
    sort(all(points));
    points.resize(unique(all(points)) - points.begin());

    vector<vector<ll>> trees, pref_sums;
    trees.reserve(len(points));
    pref_sums.reserve(len(points));

    for (auto x : points) {
        trees.emplace_back(GetSpanningTreeEdges(n, edges, x));
        sort(all(trees.back()));
        pref_sums.emplace_back(vector<ll>(n - 1));
        partial_sum(all(trees.back()), pref_sums.back().begin());
        pref_sums.back().insert(pref_sums.back().begin(), 0);
    }
    auto GetTotalWeight = [n, &pref_sums, &trees](int idx, int x) {
        auto i = lower_bound(all(trees[idx]), x) - trees[idx].begin();
        return x * i - pref_sums[idx][i] + pref_sums[idx].back() - pref_sums[idx][i] - x * (n - 1 - i);
    };
    auto AnswerQuery = [&GetTotalWeight, &points](int x) {
        auto i = lower_bound(all(points), x) - points.begin();
        cmin(i, len(points) - 1);
        return GetTotalWeight((int)i, x);
    };

    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    k -= p;
    int q;
    ll ans = 0;
    for (int i = 0; i < p; ++i) {
        cin >> q;
        ans ^= AnswerQuery(q);
    }
    for (int i = 0; i < k; ++i) {
        q = int((1ll * q * a + b) % c);
        ans ^= AnswerQuery(q);
    }
    cout << ans << endl;
}