//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
V<T> make_vec(size_t a) {
    return V<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return V<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

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

ll gcd2(ll a, ll b) {
    if (a == 0 && b == 0) return 0;
    return gcd(a, b);
}

struct U {
    using T = ll;
    static T id() { return 0; }
    static T op(const T& a, const T& b) { return gcd2(a, b); }
};

void slv() {
    int n;
    cin >> n;
    V<ll> a(n);
    rep(i, n) cin >> a[i];
    V<ll> d(n - 1);
    rep(i, n - 1) d[i] = abs(a[i + 1] - a[i]);

    segtree<U> seg(d);

    int ans = 1;

    rep(i, n - 1) {
        int lo = i, hi = n - 1;
        {
            ll d = seg.query(i, hi);
            if (d == 0 || d > 1) {
                lo = hi;
            }
        }
        while (hi - lo > 1) {
            ll m = (lo + hi) / 2;
            ll d = seg.query(i, m);
            if (d == 1) {
                hi = m;
            } else {
                lo = m;
            }
        }
        chmax(ans, lo - i + 1);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--) {
        slv();
    }

    return 0;
}