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

template <class T>
void mkuni(vector<T>& v) {
    sort(ALL(v));
    v.erase(unique(ALL(v)), end(v));
}

template <class T>
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) { return v[i] < v[j]; });
    return res;
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
void scan(vector<T>& v, T offset = T(0)) {
    for (auto& x : v) {
        cin >> x;
        x += offset;
    }
}

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

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

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

const int INF = TEN(9);
//[a],[b],[c],[ab],[bc],[abc]

struct Data {
    array<int, 64> a;
    Data() { rep(i, 64) a[i] = 0; }
    Data(int x) {
        rep(i, 64) {
            if (i >> x & 1) {
                a[i] = 0;
            } else {
                a[i] = 1;
            }
        }
    }
};

int mt[64][64];
V<int> cand;

Data add(Data p, Data q) {
    Data res;
    rep(i, 64) res.a[i] = INF;

    for (int i : cand)
        for (int j : cand) {
            chmin(res.a[mt[i][j]], p.a[i] + q.a[j]);
        }
    return res;
}

const Data mono;

struct U {
    using T = Data;
    static T id() { return mono; }
    static T op(const T& a, const T& b) { return add(a, b); }
};

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    V<int> vec(n);
    rep(i, n) vec[i] = s[i] - 'a';

    VV<int> rng{{0}, {1}, {2}, {0, 1}, {1, 2}, {0, 1, 2}};
    V<int> masks;
    rep(i, 6) {
        int m = 0;
        for (int x : rng[i]) m |= 1 << x;
        masks.pb(m);
    }

    rep(i, 64) {
        bool ok = 1;
        rep(j, 6) {
            rep(k, j) {
                if ((masks[k] & masks[j]) == masks[k] && (i >> j & 1) &&
                    !(i >> k & 1)) {
                    ok = 0;
                }
            }
        }
        if (ok) cand.pb(i);
    }
    // debug(SZ(cand), cand);

    rep(i, 64) {
        rep(j, 64) {
            int mask = i | j;
            rep(p, 6) if (i >> p & 1) {
                rep(q, 6) if (j >> q & 1) {
                    if (rng[p].back() + 1 == rng[q][0]) {
                        V<int> vv;
                        for (int x : rng[p]) {
                            vv.pb(x);
                        }
                        for (int x : rng[q]) {
                            vv.pb(x);
                        }

                        rep(t, 6) {
                            if (rng[t] == vv) {
                                mask |= 1 << t;
                            }
                        }
                    }
                }
            }
            mt[i][j] = mask;
        }
    }

    V<Data> gen;
    rep(i, n) gen.pb(Data(vec[i]));
    segtree<U> seg(gen);

    rep(qq, q) {
        int p;
        char c;
        cin >> p >> c;
        --p;
        int x = c - 'a';
        Data u = Data(x);
        seg.modify(p, u);

        auto res = seg.query(0, n);
        int ans = INF;
        rep(i, 32) { chmin(ans, res.a[i]); }
        print(ans);
    }

    return 0;
}