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

// #define TASK "magic"

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

vector<int> GetPoints(vector<pii> segs) {
    sort(all(segs), [](pii a, pii b) {
        if (a.first != b.first) {
            return a < b;
        }
        return a > b;
    });
    {
        vector<pii> st;
        for (auto& seg : segs) {
            while (!st.empty() && st.back().first <= seg.first && st.back().second >= seg.second) {
                st.kek();
            }
            st.pb(seg);
        }
        segs.swap(st);
    }
    vector<int> points;
    int last_point = segs[0].first - 1;
    for (auto& seg : segs) {
        if (last_point < seg.first) {
            points.pb(last_point = seg.second);
        }
    }
    return points;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> dishes(n);
    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> dishes[i].first >> dishes[i].second >> m[i];
    }
    vector<pii> segs(n);
    map<int, vector<pii>> segs_map;
    for (int i = 0; i < n; ++i) {
        int l = dishes[i].first - m[i], r = dishes[i].first;
        cmax(l, 0);
        r -= max(0, m[i] - dishes[i].second);
        segs_map[dishes[i].first + dishes[i].second - m[i]].emplace_back(l, r);
        segs[i] = {l, r};
    }
    map<int, vector<int>> points;
    int ans = 0;
    for (auto &[val, vec] : segs_map) {
        points[val] = GetPoints(vec);
        ans += len(points[val]);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        vector<int>& p = points[dishes[i].first + dishes[i].second - m[i]];
        size_t idx = lower_bound(all(p), segs[i].first) - p.begin();
        assert(idx != p.size() && segs[i].second >= p[idx]);
        a[i] = dishes[i].first - p[idx];
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << m[i] - a[i] << endl;;
    }
}