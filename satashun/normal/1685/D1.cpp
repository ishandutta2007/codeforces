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

void slv() {
    int n;
    cin >> n;
    V<int> p(n), rp(n);
    scan(p, -1);
    rep(i, n) rp[p[i]] = i;

    V<int> vis(n);

    VV<int> cyc;

    rep(i, n) {
        if (vis[i]) continue;
        int v = i;
        V<int> vec;
        while (!vis[v]) {
            vis[v] = 1;
            vec.pb(v);
            v = p[v];
        }
        cyc.pb(vec);
    }
    debug(cyc);

    auto dc = cyc;
    for (auto& c : dc) sort(ALL(c));

    int sz = SZ(dc);
    V<int> to = p;

    rep(tt, sz - 1) {
        int md = n;
        int ti, tj, tv, tu;
        rep(i, SZ(dc)) {
            rep(j, i) {
                for (int v : dc[i]) {
                    for (int u : dc[j]) {
                        if (abs(v - u) < md) {
                            md = abs(v - u);
                            ti = i, tj = j, tv = v, tu = u;
                        }
                    }
                }
            }
        }
        to[rp[tv]] = tu;
        to[rp[tu]] = tv;
        swap(rp[tu], rp[tv]);

        V<int> nxt(SZ(dc[ti]) + SZ(dc[tj]));
        merge(ALL(dc[ti]), ALL(dc[tj]), nxt.begin());
        dc.erase(dc.begin() + tj);
        dc.erase(dc.begin() + ti - 1);
        dc.pb(nxt);
    }

    debug(to);

    V<int> rq;
    int v = 0;
    while (true) {
        rq.pb(v);
        v = to[v];
        if (v == 0) break;
    }
    auto q = rq;
    reverse(ALL(q));
    for (auto& x : q) x++;
    show(q);

    int score = 0;
    rep(i, n) score += abs(to[i] - p[i]);
    debug(score);
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}