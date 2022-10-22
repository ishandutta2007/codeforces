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
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
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

// modify only U

constexpr ll INF = TEN(9) + 10;

struct U {
    using T = ll;
    static T id() { return -INF; }
    static T op(const T& a, const T& b) { return max(a, b); }
};

template <class T>
V<T> cumsum(const V<T>& vec) {
    int n = vec.size();
    V<T> res(n + 1);
    rep(i, n) { res[i + 1] = res[i] + vec[i]; }
    return res;
}

template <class T>
V<int> compress(const V<T>& vec) {
    int n = SZ(vec);
    auto xs = vec;
    mkuni(xs);
    V<int> res(n);
    rep(i, n) { res[i] = lower_bound(ALL(xs), vec[i]) - xs.begin(); }
    return res;
}

void slv() {
    int n;
    cin >> n;
    V<ll> a(n);
    cin >> a;
    auto ps_ = cumsum(a);
    auto ps = compress(ps_);
    debug(ps);

    segtree<U> seg1(n + 1), seg2(n + 1);
    V<ll> dp(n + 1);
    map<ll, ll> mem;

    {
        int p = ps[0];
        seg1.modify(p, 0ll);
        seg2.modify(p, 0ll);
        mem[p] = 0;
    }

    rep(i, n) {
        int p = ps[i + 1];
        ll val = -INF;
        auto v1 = seg1.query(0, p);
        if (v1 != INF) {
            chmax(val, v1 + i + 1);
        }
        auto v2 = seg2.query(p + 1, n + 1);
        if (v2 != INF) {
            chmax(val, v2 - i - 1);
        }
        if (mem.count(p)) {
            chmax(val, mem[p]);
        }

        {
            ll x1 = seg1.query(p, p + 1);
            seg1.modify(p, max(x1, val - i - 1));
        }

        {
            ll x2 = seg2.query(p, p + 1);
            seg2.modify(p, max(x2, val + i + 1));
        }

        if (mem.count(p)) {
            chmax(mem[p], val);
        } else {
            mem[p] = val;
        }
        dp[i + 1] = val;
    }
    show(dp[n]);
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}