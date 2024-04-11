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

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;

VV<int> ng;

void slv() {
    int n, m;
    cin >> n >> m;
    V<int> a(n);
    cin >> a;
    map<int, int> T;
    rep(i, n) T[a[i]]++;
    V<pii> vec;
    for (auto [p, q] : T) {
        vec.eb(p, q);
    }
    debug(vec);

    V<int> cx;
    int sz = SZ(vec);
    rep(i, sz) cx.pb(vec[i].se);
    mkuni(cx);

    VV<int> cand(SZ(cx));
    map<int, int> id;

    rep(i, sz) {
        int p = lower_bound(ALL(cx), vec[i].se) - cx.begin();
        cand[p].pb(vec[i].fi);
        id[vec[i].fi] = i;
    }

    ll ans = 0;

    rep(i, SZ(cand)) {
        sort(ALL(cand[i]));
        reverse(ALL(cand[i]));
    }

    VV<pii> ng(sz);
    rep(i, sz) {
        int p = lower_bound(ALL(cx), vec[i].se) - cx.begin();
        ng[i].eb(p, vec[i].fi);
    }

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        int p = lower_bound(ALL(cx), T[x]) - cx.begin();
        int q = lower_bound(ALL(cx), T[y]) - cx.begin();
        ng[id[x]].eb(q, y);
        ng[id[y]].eb(p, x);
    }

    rep(i, sz) {
        sort(ALL(ng[i]), [&](auto a, auto b) {
            if (a.fi != b.fi)
                return a.fi < b.fi;
            else
                return a.se > b.se;
        });
    }

    rep(i, sz) {
        int piv = 0;
        auto [x, c] = vec[i];
        // debug(ng[i]);

        rep(j, SZ(cand)) {
            while (piv < SZ(ng[i]) && ng[i][piv].fi < j) piv++;
            for (auto y : cand[j]) {
                while (piv < SZ(ng[i]) &&
                       (ng[i][piv].fi == j && ng[i][piv].se > y)) {
                    piv++;
                }
                if (!(piv < SZ(ng[i]) && ng[i][piv].fi == j &&
                      ng[i][piv].se == y)) {
                    ll a = cx[j] + c;
                    ll b = x + y;
                    chmax(ans, a * b);
                    break;
                }
            }
        }
    }

    print(ans);
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}