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
const ll INFll = 4e18l + 666;
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

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p) {
    return in >> p.first >> p.second;
}

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(l) {}
 
    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

private:
    TLambda l_;
};

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

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree(int sz) : n(sz) {
        while (n & (n - 1)) ++n;
        tree.resize(2 * n - 1, INFll);
    }

    void update(int idx, ll val) {
        idx += n - 1;
        cmin(tree[idx], val);
        while (idx > 0) {
            idx = (idx - 1) >> 1;
            tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) const {
        if (l >= tr || r <= tl) return INFll;
        if (tl >= l && tr <= r) return tree[v];
        int mid = (tl + tr) >> 1;
        return min(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid, tr, l, r));
    }

    ll query(int l, int r) const {
        return query(0, 0, n, l, r);
    }
};

void GenSegs(const vector<pii>& v, auto&& callback) {
    vector<pii> stack;
    for (int i = 0; i < len(v); ++i) {
        while (!stack.empty() && stack.back().second > v[i].second) {
            stack.kek();
        }
        if (!stack.empty()) {
            callback(i, stack.back().first);
        }
        stack.pb({i, v[i].second});
    }
}

void run() {
    int n, q;
    cin >> n >> q;
    vector<pii> v(n);
    cin >> v;

    auto GetCost = [&](int i, int j) {
        return 1ll * abs(v[i].first - v[j].first) * (v[i].second + v[j].second);
    };

    vector<tuple<int, int, ll>> segs;
    GenSegs(v, [&](int i, int j) {
        int l = i, r = j;
        if (l > r) swap(l, r);
        segs.pb({l, r, GetCost(l, r)});
    });
    reverse(all(v));
    GenSegs(v, [&](int i, int j) {
        int l = n - i - 1, r = n - j - 1;
        if (l > r) swap(l, r);
        segs.pb({l, r, GetCost(i, j)});
    });
    reverse(all(v));
    vector<array<int, 3>> events;
    vector<pii> queires(q);
    cin >> queires;
    for (auto& [l, r] : queires) {
        --l, --r;
    }
    events.reserve(len(segs) + q);
    for (int i = 0; i < len(segs); ++i) {
        auto [l, r, val] = segs[i];
        events.pb({r, 0, i});
    }
    for (int i = 0; i < q; ++i) {
        auto [l, r] = queires[i];
        events.pb({r, 1, i});
    }
    sort(all(events));
    SegTree t(n);
    vector<ll> ans(q, -1);
    for (auto [r, tp, idx] : events) {
        if (tp == 0) {
            auto [l, r, val] = segs[idx];
            t.update(l, val);
        } else {
            auto [l, r] = queires[idx];
            ans[idx] = t.query(l, n);
        }
    }
    for (auto x : ans) {
        cout << x << '\n';
    }
}