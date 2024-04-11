#pragma region satashun
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
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

template <typename T, typename V>
void fill_vec(vector<T>& vec, const V& val, int len) {
    vec.assign(len, val);
}
template <typename T, typename V, typename... Ts>
void fill_vec(vector<T>& vec, const V& val, int len, Ts... ts) {
    vec.resize(len),
        for_each(begin(vec), end(vec), [&](T& v) { fill_vec(v, val, ts...); });
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

template <typename T>
int arglb(const V<T>& v, const T& x) {
    return distance(v.begin(), lower_bound(ALL(v), x));
}

template <typename T>
int argub(const V<T>& v, const T& x) {
    return distance(v.begin(), upper_bound(ALL(v), x));
}

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v, bool increasing = true) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);

    if (increasing) {
        stable_sort(res.begin(), res.end(),
                    [&](int i, int j) { return v[i] < v[j]; });
    } else {
        stable_sort(res.begin(), res.end(),
                    [&](int i, int j) { return v[i] > v[j]; });
    }
    return res;
}

template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
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

template <class T>
ostream& operator<<(ostream& os, const set<T>& ST) {
    os << "{";
    for (auto it = ST.begin(); it != ST.end(); ++it) {
        if (it != ST.begin()) os << ",";
        os << *it;
    }
    os << "}";
    return os;
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& MP) {
    for (auto it = MP.begin(); it != MP.end(); ++it) {
        os << "(" << it->first << ": " << it->second << ")";
    }
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

template <class T>
V<T>& operator+=(V<T>& vec, const T& v) {
    for (auto& x : vec) x += v;
    return vec;
}

template <class T>
V<T>& operator-=(V<T>& vec, const T& v) {
    for (auto& x : vec) x -= v;
    return vec;
}

// suc : 1 = newline, 2 = space
template <class T>
void print(T x, int suc = 1) {
    cout << x;
    if (suc == 1)
        cout << "\n";
    else if (suc == 2)
        cout << " ";
}

template <class T>
void print(const vector<T>& v, int suc = 1) {
    for (int i = 0; i < v.size(); ++i)
        print(v[i], i == int(v.size()) - 1 ? suc : 2);
}

template <class T>
void show(T x) {
    print(x, 1);
}

template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
    print(H, 2);
    show(T...);
}

int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(int a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(int t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
int bit_parity(int t) { return __builtin_parity(t); }
int bit_parity(ll t) { return __builtin_parityll(t); }

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;
#pragma endregion satashun

// index of root = 1
template <class U>
struct segtree {
    using T = typename U::T;
    int sz;
    V<T> dat;

    segtree() {}
    segtree(int n) : _n(n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(sz * 2, U::id());
    }

    segtree(const V<T>& a) {
        int n = a.size();
        _n = n;
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

    T get(int p) const { return dat[p + sz]; }

    //[l, r)
    T query(int l, int r) const {
        T lval = U::id(), rval = U::id();
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op(lval, dat[l++]);
            if (r & 1) rval = U::op(dat[--r], rval);
        }
        return U::op(lval, rval);
    }

    // https://atcoder.jp/contests/practice2/submissions/33977727
    // https://github.com/atcoder/ac-library/blob/master/atcoder/segtree.hpp
    // find max r s.t. f([l, r)) = true
    template <class F>
    int max_right(int l, F f) const {
        // assert(0 <= l && l <= _n);
        // assert(f(U::id()));

        if (l == sz) return sz;
        l += sz;
        auto cur = U::id();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(U::op(cur, dat[l]))) {
                while (l < sz) {
                    l = l * 2;
                    if (f(U::op(cur, dat[l]))) {
                        cur = U::op(cur, dat[l]);
                        l++;
                    }
                }
                return l - sz;
            }
            cur = U::op(cur, dat[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    // needs verification
    // find min l s.t. f([l, r)) = true
    template <class F>
    int min_left(int r, F f) const {
        // assert(0 <= r && r <= _n);
        // assert(f(U::id()));

        if (r == 0) return 0;
        r += sz;
        auto cur = U::id();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(U::op(dat[r], cur))) {
                while (r < sz) {
                    r = (2 * r + 1);
                    if (f(U::op(dat[r], cur))) {
                        cur = U::op(dat[r], cur);
                        r--;
                    }
                }
                return r + 1 - sz;
            }
            cur = U::op(dat[r], cur);
        } while ((r & -r) != r);
        return 0;
    }

   private:
    int _n;
};

constexpr ll INF = TEN(18);

// modify only U
struct U {
    using T = ll;
    static T id() { return -INF; }
    static T op(const T& a, const T& b) { return max(a, b); }
};

// O(sqrt(x))
V<ll> enum_div(ll x) {
    V<ll> vec;
    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            vec.pb(i);
            if (x != i * i) {
                vec.pb(x / i);
            }
        }
    }
    sort(ALL(vec));
    return vec;
}

void slv() {
    int n, q;
    cin >> n >> q;
    V<ll> a(n);
    cin >> a;

    auto dn = enum_div(n);
    dn.pop_back();

    int sz = SZ(dn);
    VV<ll> sums(sz);
    // V<multiset<ll>> sts(sz);
    V<segtree<U>> segs(sz);

    rep(i, sz) {
        int d = dn[i];
        sums[i].resize(d);
        rep(j, n) { sums[i][j % d] += a[j]; }
    }

    {
        ll mx = 0;
        rep(i, sz) {
            rep(j, dn[i]) {
                // sts[i].insert(sums[i][j]);
                chmax(mx, sums[i][j] * dn[i]);
            }
            segs[i] = segtree<U>(sums[i]);
        }
        show(mx);
    }

    rep(tt, q) {
        int p, x;
        cin >> p >> x;
        --p;

        ll mx = 0;

        rep(i, sz) {
            int md = p % dn[i];
            // segs[i].modify();
            // sts[i].erase(sts[i].find(sums[i][md]));
            sums[i][md] += x - a[p];
            segs[i].modify(md, sums[i][md]);
            ll vm = segs[i].query(0, dn[i]);

            // sts[i].insert(sums[i][md]);
            // ll vm = *(--sts[i].end());
            chmax(mx, vm * dn[i]);
            //  rep(j, dn[i]) { chmax(mx, sums[i][j] * dn[i]); }
        }

        show(mx);

        a[p] = x;
    }
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}