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

//[l,r]
ll ask(int l, int r) {
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    cout.flush();
    ll x;
    cin >> x;
    return x;
}

void answer(int i, int j, int k) {
    cout << "! " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    cout.flush();
}

ll tri(ll x) {
    if (x == 0) return 0;
    ll lo = 0, hi = TEN(9) + 1;
    while (hi - lo > 1) {
        ll m = (lo + hi) / 2;
        if (m * (m - 1) / 2 <= x) {
            lo = m;
        } else {
            hi = m;
        }
    }
    if (lo * (lo - 1) / 2 == x) {
        return lo;
    } else
        return -1;
}

void slv() {
    int n;
    cin >> n;
    int lo = 0, hi = n - 1;
    while (hi - lo > 1) {
        ll m = (lo + hi) / 2;
        ll inv = ask(0, m);
        // ll tr = tri(inv);
        if (inv > 0) {
            hi = m;
        } else {
            lo = m;
        }
    }
    int i = lo;
    ll inv = ask(lo, n - 1);
    ll invd = ask(lo + 1, n - 1);
    int wl = inv - invd;
    int j = lo + wl + 1;
    ll invr = ask(j, n - 1);
    int wr = tri(invr);
    int k = j + wr - 1;
    answer(i, j, k);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        slv();
    }
    return 0;
}