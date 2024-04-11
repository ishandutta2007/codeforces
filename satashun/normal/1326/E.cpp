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

// index of root = 1
// T1 : array value type
// T2 : action type

template <class U>
struct segtree {
    using T1 = typename U::T1;
    using T2 = typename U::T2;
    int sz, H;

    V<T1> a;
    V<T2> b;

    segtree() { sz = H = -1; }
    segtree(int n) {
        sz = 1, H = 0;
        while (sz < n) {
            sz *= 2, ++H;
        }
        a.assign(sz * 2, U::id1());
        b.assign(sz * 2, U::id2());
    }

    segtree(const V<T1>& vec) {
        int n = vec.size();
        sz = 1, H = 0;
        while (sz < n) {
            sz *= 2, ++H;
        }

        a.assign(sz * 2, U::id1());
        b.assign(sz * 2, U::id2());

        for (int i = 0; i < n; ++i) {
            a[sz + i] = vec[i];
        }
        for (int i = sz - 1; i >= 1; --i) {
            a[i] = U::op11(a[i << 1 | 0], a[i << 1 | 1]);
        }
    }

    void up(int i) {
        while (i >>= 1) {
            T1 xl = U::op21(b[i << 1 | 0], a[i << 1 | 0]);
            T1 xr = U::op21(b[i << 1 | 1], a[i << 1 | 1]);
            a[i] = U::op11(xl, xr);
        }
    }

    void propagate(int p) {
        for (int h = H; h > 0; --h) {
            int i = p >> h;
            a[i] = U::op21(b[i], a[i]);
            b[i << 1 | 0] = U::op22(b[i], b[i << 1 | 0]);
            b[i << 1 | 1] = U::op22(b[i], b[i << 1 | 1]);
            b[i] = U::id2();
        }
    }

    // action on [p, q)
    void apply(int p, int q, T2 x) {
        if (p == q) return;
        p += sz, q += sz;
        propagate(p);
        propagate(q - 1);

        for (int l = p, r = q; l < r; l >>= 1, r >>= 1) {
            if (l & 1) b[l] = U::op22(x, b[l]), ++l;
            if (r & 1) --r, b[r] = U::op22(x, b[r]);
        }
        up(p);
        up(q - 1);
    }

    T1 get(int l, int r) {
        if (l == r) return U::id1();
        l += sz, r += sz;
        propagate(l);
        propagate(r - 1);

        T1 lval = U::id1(), rval = U::id1();

        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lval = U::op11(lval, U::op21(b[l], a[l])), ++l;
            if (r & 1) --r, rval = U::op11(U::op21(b[r], a[r]), rval);
        }
        return U::op11(lval, rval);
    }
};

// for https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d
// range addition and range minimum query needed, initialization must be cared
// (set all to 0, while id1 = INF)

// modify only U for use

constexpr ll INF = TEN(9);

struct U {
    using T1 = int;
    using T2 = int;
    static T1 id1() { return -INF; }
    static T2 id2() { return 0; }
    static T1 op11(const T1& a, const T1& b) { return max(a, b); }
    static T1 op21(const T2& b, const T1& a) { return b + a; }
    static T2 op22(const T2& a, const T2& b) { return a + b; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    V<int> p(n), q(n), rp(n);
    rep(i, n) {
        cin >> p[i];
        --p[i];
        rp[p[i]] = i;
    }

    rep(i, n) {
        cin >> q[i];
        --q[i];
    }

    V<int> ini(n);
    segtree<U> seg(ini);

    V<int> ans(n, -1);

    int pr = n;
    rep(i, n) {
        while (seg.get(0, n) <= 0) {
            pr--;
            seg.apply(0, rp[pr] + 1, 1);
        }

        ans[i] = pr + 1;
        debug(i, pr);

        seg.apply(0, q[i] + 1, -1);
    }

    print(ans);

    return 0;
}