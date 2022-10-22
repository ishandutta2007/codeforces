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
vector<int> sort_by(const vector<T>& v) {
    vector<int> res(v.size());
    iota(res.begin(), res.end(), 0);
    stable_sort(res.begin(), res.end(),
                [&](int i, int j) { return v[i] < v[j]; });
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

template <class T>
struct segtree {
    int sz;
    vector<T> dat1, dat2;

    segtree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        dat1.resize(sz * 2, 0);
        dat2.resize(sz * 2, 0);
    }

    void add(int a, int b, T x, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b)
            dat1[k] += x;
        else {
            dat2[k] += x * (min(b, r) - max(a, l));
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        }
    }

    T sum(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b)
            return dat1[k] * (r - l) + dat2[k];
        else {
            T res = dat1[k] * (min(b, r) - max(a, l));
            res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
            res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
            return res;
        }
    }

    void add(int a, int b, T x) { add(a, b, x, 0, 0, sz); }
    T sum(int a, int b) { return sum(a, b, 0, 0, sz); }
};

// a <= x <= b, c <= y <= d
struct Rect {
    int a, b, c, d;
    Rect() {}
    Rect(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};

struct Event {
    int x, ly, ry, tp;
    Event() {}
    Event(int x, int ly, int ry, int tp) : x(x), ly(ly), ry(ry), tp(tp) {}
    bool operator<(const Event& a) const {
        if (x != a.x)
            return x > a.x;
        else
            return tp < a.tp;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    V<int> p(n), rp(n + 1, -1);
    V<pii> rng(q);
    VV<int> dv(n + 1);

    for (int d = 1; d <= n; ++d) {
        for (int x = d; x <= n; x += d) {
            dv[x].pb(d);
        }
    }

    cin >> p >> rng;
    rep(i, n) rp[p[i]] = i;

    auto idx = sort_by(p);
    set<int> st;
    st.insert(-1);
    st.insert(n);
    rep(i, n) st.insert(i);
    V<Rect> qr;

    for (int i : idx) {
        int x = p[i];
        auto it = st.lower_bound(i);
        int lt = *prev(it) + 1, rt = *next(it) - 1;
        debug(i, x, lt, rt);
        st.erase(i);

        // x = 1 : ng
        // lt <= l <= i, i <= r <= rt

        if (x == 1) continue;
        int lm = -1, rm = n;

        V<pii> vec;

        for (int d : dv[x]) {
            if (d == x / d) continue;
            int pl = rp[d], pr = rp[x / d];
            if (pl > pr) swap(pl, pr);
            if (pr < lt || pl > rt || pl < lt || pr > rt) continue;
            if (pr <= i) {
                chmax(lm, pl);
            } else if (pl >= i) {
                chmin(rm, pr);
            } else {
                vec.eb(pl, pr);
            }
        }
        if (lm != -1 && lt <= lm) {
            qr.eb(lt, lm, i, rt);
            lt = lm + 1;
        }
        if (rm != n && rm <= rt) {
            qr.eb(lt, i, rm, rt);
            rt = rm - 1;
        }
        // lt <= x <= i,

        sort(ALL(vec), [&](auto p, auto q) {
            if (p.fi != q.fi)
                return p.fi < q.fi;
            else
                return p.se > q.se;
        });
        {
            V<pii> nx;
            for (auto [l, r] : vec) {
                if (l <= lm || r >= rm) continue;
                while (SZ(nx) && nx.back().se >= r) {
                    nx.pop_back();
                }
                nx.eb(l, r);
            }
            vec = nx;
        }
        debug(vec);

        int la = lt;

        for (auto [l, r] : vec) {
            qr.eb(la, l, r, rt);
            la = l + 1;
        }
    }

    V<Event> vec;
    // vec.reserve(q + SZ(qr) * 2);

    for (auto rect : qr) {
        debug(rect.a, rect.b, rect.c, rect.d);
        if (rect.a > rect.b || rect.c > rect.d) continue;
        vec.eb(rect.b, rect.c, rect.d + 1, -2);
        vec.eb(rect.a - 1, rect.c, rect.d + 1, -1);
    }

    for (auto& [l, r] : rng) {
        --l;
        --r;
    }

    rep(i, q) {
        auto [l, r] = rng[i];
        vec.eb(l, 0, r + 1, i);
    }
    sort(ALL(vec));

    V<int> sum(n + 1);
    V<ll> ans(q);

    segtree<ll> seg(n + 10);
    segtree<ll> seg2(n + 10);

    for (auto ev : vec) {
        int x = ev.x, ly = ev.ly, ry = ev.ry, tp = ev.tp;
        debug(x, ly, ry, tp);
        if (tp == -2) {
            seg2.add(ly, ry, 1);
            seg.add(ly, ry, x);
        } else if (tp == -1) {
            seg2.add(ly, ry, -1);
            seg.add(ly, ry, -x);
        } else {
            ll v = seg.sum(0, ry);
            v -= seg2.sum(0, ry) * (x - 1);
            ans[tp] = v;
        }
    }

    rep(i, q) show(ans[i]);

    /*
        for (auto rect : qr) {
            debug(rect.a, rect.b, rect.c, rect.d);
            for (int i = rect.a; i <= rect.b; ++i) {
                for (int j = rect.c; j <= rect.d; ++j) {
                    val[i][j]++;
                }
            }
        }

        rep(i, n) {
            rep(j, n) { assert(val[i][j] <= 1); }
        }

        for (auto [l, r] : rng) {
            --l;
            --r;
            int ans = 0;
            for (int i = l; i <= r; ++i) {
                for (int j = i; j <= r; ++j) {
                    ans += val[i][j];
                }
            }
            show(ans);
        }*/

    return 0;
}