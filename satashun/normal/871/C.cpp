#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

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

template <unsigned int MOD>
struct ModInt {
    using uint = unsigned int;
    using ull = unsigned long long;
    using M = ModInt;

    uint v;

    ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const { return v != 0; }
    M operator+(const M& a) const { return M().set_norm(v + a.v); }
    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
    M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
    M operator/(const M& a) const { return *this * a.inv(); }
    M& operator+=(const M& a) { return *this = *this + a; }
    M& operator-=(const M& a) { return *this = *this - a; }
    M& operator*=(const M& a) { return *this = *this * a; }
    M& operator/=(const M& a) { return *this = *this / a; }
    M operator-() const { return M() - *this; }
    M& operator++(int) { return *this = *this + 1; }
    M& operator--(int) { return *this = *this - 1; }

    M pow(ll n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const {
        ll a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    static int get_mod() { return MOD; }
};

class unionfind {
    vector<int> par, rank;

   public:
    void init(int n) {
        par.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) { return (find(x) == find(y)); }
};

using Mint = ModInt<1000000007>;

const int maxn = 100010;

Mint p2[maxn];
V<pii> g[maxn * 2];

int main() {
    p2[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p2[i] = p2[i - 1] * 2;
    }

    int n;
    cin >> n;
    V<pii> pts(n);
    V<int> xs, ys;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        xs.pb(x);
        ys.pb(y);
        pts[i] = mp(x, y);
    }
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    sort(ALL(ys));
    ys.erase(unique(ALL(ys)), ys.end());

    V<bool> vis(xs.size() + ys.size());
    unionfind uf;
    uf.init(vis.size());
    V<int> use(vis.size()), en(vis.size()), vn(vis.size());

    rep(i, n) {
        int a = lower_bound(ALL(xs), pts[i].fi) - xs.begin();
        int b = lower_bound(ALL(ys), pts[i].se) - ys.begin();
        use[a]++;
        use[b + xs.size()]++;
        uf.unite(a, b + xs.size());
        pts[i] = mp(a, b);
    }

    rep(i, n) { en[uf.find(pts[i].fi)]++; }
    rep(i, vis.size()) {
        int v = uf.find(i);
        vn[v]++;
    }

    set<int> st;
    Mint ans = 1;
    rep(i, vis.size()) {
        int v = uf.find(i);
        if (st.count(v)) continue;
        st.insert(v);
        if (en[v] >= vn[v]) {
            ans *= p2[vn[v]];
        } else {
            ans *= p2[vn[v]] - 1;
        }
    }
    cout << ans << endl;

    return 0;
}