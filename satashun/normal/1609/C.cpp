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

const int X = 2e6;

bitset<X> is_prime;
vector<int> pr;

int mu[X];

void init() {
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;
    mu[1] = 1;
    for (int i = 2; i < X; i++) {
        if (is_prime[i]) {
            pr.push_back(i);
            mu[i] = -1;
        }
        for (int p : pr) {
            if (ll(i) * p >= X) break;
            is_prime[i * p] = false;
            mu[i * p] = -mu[i];
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            }
        }
    }
}

void slv() {
    int e, n;
    cin >> n >> e;
    V<int> a(n);
    scan(a);

    ll ans = 0;

    rep(r, e) {
        V<int> vec;
        for (int i = r; i < n; i += e) {
            vec.pb(a[i]);
        }
        //  debug(r, vec);

        int sz = SZ(vec);
        V<int> pos;
        pos.pb(-1);

        rep(i, sz) {
            int x = vec[i];

            if (x > 1 && !is_prime[x]) {
                pos.clear();
                pos.pb(i);
                continue;
            }

            if (is_prime[x]) {
                pos.pb(i);
            }
            if (SZ(pos) >= 2) {
                ans += pos.back() - pos[SZ(pos) - 2];
                if (pos.back() == i) ans--;
            }
        }
        // debug(r, ans);
    }
    print(ans);
}

int main() {
    init();
    int tc;
    cin >> tc;
    while (tc--) slv();
    return 0;
}