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

template <class T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(int _n = 0) : n(_n), bit(n + 1) {}

    // sum of [0, i), 0 <= i <= n
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // 0 <= i < n
    void add(int i, T x) {
        ++i;
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    //[l, r) 0 <= l < r < n
    T sum(int l, int r) { return sum(r) - sum(l); }

    // verify!!!!
    // smallest i, sum(i) >= w, none -> n + 1
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int x = 0, l = 1;
        while (l * 2 <= n) l *= 2;

        for (int k = l; k > 0; k /= 2) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

void slv() {
    int n, m;
    cin >> n >> m;
    V<int> a(n * m);
    cin >> a;
    V<int> idx(n * m);
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](int i, int j) {
        if (a[i] != a[j])
            return a[i] < a[j];
        else
            return i > j;
    });

    map<int, V<int>> vv;
    rep(i, n * m) vv[a[i]].pb(i);

    V<BIT<int>> bit(n);
    rep(i, n) bit[i] = BIT<int>(m + 1);
    V<pii> pos(n * m);
    rep(i, n * m) pos[i] = mp(-1, -1);

    int cur = 0;
    int ans = 0;

    for (auto [_, vec] : vv) {
        int sz = SZ(vec);
        reverse(ALL(vec));
        int cs = sz;

        int row = cur / m;
        int col = cur % m;
        int rem = m - col;

        //   debug(vec, row, col, sz, cur, ans);

        if (sz <= rem) {
            // debug("waf");
            rep(i, sz) { pos[vec[i]] = mp(row, col + i); }
        } else {
            rep(i, rem) { pos[vec[sz - 1 - i]] = mp(row, col + rem - 1 - i); }
            row++;
            sz -= rem;
            row += sz / m;
            sz %= m;
            rep(i, sz) { pos[vec[i]] = mp(row, i); }
        }
        // debug(cur, cs);
        cur += cs;
    }
    for (auto p : pos) {
        if (p.fi == -1) continue;
        ans += bit[p.fi].sum(p.se);
        bit[p.fi].add(p.se, 1);
    }

    print(ans);
}

int main() {
    int cases = 0;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}