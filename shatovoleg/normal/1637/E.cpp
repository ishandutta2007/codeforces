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

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

pii norm(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    return {x, y};
}

pii norm(pii p) {
    return norm(p.first, p.second);
}

constexpr pii none = {-1, -1};

struct PairGenerator1 {
    PairGenerator1(const vector<int>& vals) : vals(vals) {
        it.resize(len(vals));
        iota(all(it), 1);
        for (int i = 0; i + 1 < len(vals); ++i) {
            q.push({vals[i] + vals[it[i]], i});
        }
    }

    pii Get() {
        if (q.empty()) {
            return none;
        }
        auto [val, idx] = q.top();
        q.pop();
        pii res = {vals[idx], vals[it[idx]]};
        ++it[idx];
        if (it[idx] < len(vals)) {
            q.push({vals[idx] + vals[it[idx]], idx});
        }
        return res;
    }

    const vector<int>& vals;
    vector<int> it;
    priority_queue<pii> q;
};

struct PairGenerator2 {
    PairGenerator2(const vector<int>& v1, const vector<int>& v2) : vals1(v1), vals2(v2) {
        it.push_back(0);
        q.push({vals1[0] + vals2[0], 0});
    }

    pii Get() {
        if (q.empty()) {
            return none;
        }
        auto [sm, idx] = q.top();
        q.pop();
        pii ret = {vals1[idx], vals2[it[idx]]};
        ++it[idx];
        if (it[idx] != len(vals2)) {
            q.push({vals1[idx] + vals2[it[idx]], idx});
        }
        if (idx + 1 == len(it) && len(it) != len(vals1)) {
            it.push_back(0);
            q.push({vals1[idx + 1] + vals2[0], idx + 1});
        }
        return ret;
    }

    const vector<int>& vals1;
    const vector<int>& vals2;
    vector<int> it;
    priority_queue<pii> q;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    set<pii> denied;
    {
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            denied.insert(norm(x, y));
        }
    }
    map<int, int> cnt;
    for (auto x : a) {
        ++cnt[x];
    }
    map<int, vector<int>> groups;
    for (auto [x, y] : cnt) {
        groups[y].pb(x);
    }
    for (auto& [_, arr] : groups) {
        sort(all(arr));
        reverse(all(arr));
    }
    ll ans = 0;
    for (auto& [cnt, vals] : groups) {
        if (len(vals) == 1) continue;
        PairGenerator1 gen(vals);
        while (true) {
            auto p = gen.Get();
            if (p == none) break;
            if (!denied.count(norm(p))) {
                auto [x, y] = p;
                assert(x != y);
                cmax(ans, 1ll * cnt * 2 * (x + y));
                break;
            }
        }
    }
    for (auto& [cnt1, vals1] : groups) {
        for (auto& [cnt2, vals2] : groups) {
            if (cnt1 >= cnt2) continue;
            PairGenerator2 gen(vals1, vals2);
            while (true) {
                auto p = gen.Get();
                if (p == none) break;
                if (!denied.count(norm(p))) {
                    auto [x, y] = p;
                    cmax(ans, 1ll * (cnt1 + cnt2) * (x + y));
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}