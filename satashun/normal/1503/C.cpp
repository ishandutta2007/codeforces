//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ull = uint64_t;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

// index of root = 1

template <class U>
struct segtree {
    using T = typename U::T;
    int sz;
    V<T> dat;

    segtree() {}
    segtree(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, U::id());
    }

    segtree(const V<T>& a) {
        int n = a.size();
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, U::id());
        for (int i = 0; i < n; ++i) {
            dat[sz + i] = a[i];
        }
        for (int i = sz - 1; i >= 1; --i) {
            upd(i);
        }
    }

    void upd(int p) { dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]); }

    void build() {
        for (int i = sz - 1; i > 0; --i) {
            dat[i] = U::op(dat[i << 1], dat[i << 1 | 1]);
        }
    }

    void modify(int p, T v) {
        p += sz;
        dat[p] = v;
        while (p >>= 1) {
            dat[p] = U::op(dat[p << 1], dat[p << 1 | 1]);
        }
    }

    //[l, r)

    T query(int l, int r) {
        T lval = U::id(), rval = U::id();
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op(lval, dat[l++]);
            if (r & 1) rval = U::op(dat[--r], rval);
        }
        return U::op(lval, rval);
    }
};

// modify only U for use

constexpr ll INF = TEN(18) + 10;

struct U {
    using T = ll;
    static T id() { return INF; }
    static T op(const T& a, const T& b) { return min(a, b); }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    V<pii> vec;

    ll ans = 0;

    rep(i, n) {
        int a, c;
        cin >> a >> c;
        vec.eb(a, c);
        ans += c;
    }

    sort(ALL(vec));

    V<int> xs;
    rep(i, n) {
        xs.pb(vec[i].fi + vec[i].se);
        xs.pb(vec[i].fi);
    }
    sort(ALL(xs));

    V<ll> dp(n, INF);
    segtree<U> seg1(SZ(xs)), seg2(SZ(xs));

    auto getp = [&](int x) { return lower_bound(ALL(xs), x) - xs.begin(); };

    {
        int q = getp(vec[0].fi + vec[0].se);
        dp[0] = 0;
        seg1.modify(q, dp[0]);
        seg2.modify(q, dp[0] - vec[0].fi - vec[0].se);
    }

    for (int i = 1; i < n; ++i) {
        int p = getp(vec[i].fi);
        int q = getp(vec[i].fi + vec[i].se);
        dp[i] = min(seg1.query(p, SZ(xs)), seg2.query(0, p) + vec[i].fi);
        seg1.modify(q, dp[i]);
        seg2.modify(q, dp[i] - vec[i].fi - vec[i].se);
    }

    cout << ans + dp.back() << endl;
    return 0;
}