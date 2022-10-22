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

template <typename T, typename V>
void fill_vec(vector<T>& vec, const V& val, int len) {
    vec.assign(len, val);
}
template <typename T, typename V, typename... Ts>
void fill_vec(vector<T>& vec, const V& val, int len, Ts... ts) {
    vec.resize(len),
        for_each(begin(vec), end(vec), [&](T& v) { fill_vec(v, val, ts...); });
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

template <typename T>
int arglb(const V<T>& v, const T& x) {
    return distance(v.begin(), lower_bound(ALL(v), x));
}

template <typename T>
int argub(const V<T>& v, const T& x) {
    return distance(v.begin(), upper_bound(ALL(v), x));
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

template <class T>
ostream& operator<<(ostream& os, const set<T>& ST) {
    os << "{";
    for (auto it = ST.begin(); it != ST.end(); ++it) {
        if (it != ST.begin()) os << ",";
        os << *it;
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

string to_string(__int128_t x) {
    if (x == 0) return "0";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }

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
V<T>& operator+=(V<T>& vec, const T& v) {
    for (auto& x : vec) x += v;
    return vec;
}

template <class T>
V<T>& operator-=(V<T>& vec, const T& v) {
    for (auto& x : vec) x -= v;
    return vec;
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

int topbit(int t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(int a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(int t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
int bit_parity(int t) { return __builtin_parity(t); }
int bit_parity(ll t) { return __builtin_parityll(t); }

struct prepare_io {
    prepare_io() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
    }
} prep_io;
#pragma endregion satashun

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
    explicit operator int() const { return v; }
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

    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    friend istream& operator>>(istream& in, M& x) {
        ll v_;
        in >> v_;
        x = M(v_);
        return in;
    }

    bool operator<(const M& r) const { return v < r.v; }
    bool operator>(const M& r) const { return v < *this; }
    bool operator<=(const M& r) const { return !(r < *this); }
    bool operator>=(const M& r) const { return !(*this < r); }
    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }

    static uint get_mod() { return MOD; }
};

// using Mint = ModInt<1000000007>;
using Mint = ModInt<998244353>;

V<Mint> fact, ifact, inv;
VV<Mint> small_comb;

void mod_init() {
    const int maxv = 1000010;
    const int maxvv = 5000;

    fact.resize(maxv);
    ifact.resize(maxv);
    inv.resize(maxv);

    small_comb = make_vec<Mint>(maxvv, maxvv);

    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    ifact[maxv - 1] = fact[maxv - 1].inv();

    for (int i = maxv - 2; i >= 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = ifact[i] * fact[i - 1];
    }

    for (int i = 0; i < maxvv; ++i) {
        small_comb[i][0] = small_comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            small_comb[i][j] = small_comb[i - 1][j] + small_comb[i - 1][j - 1];
        }
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    if (n < small_comb.size()) return small_comb[n][r];
    return fact[n] * ifact[r] * ifact[n - r];
}

Mint inv_comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return ifact[n] * fact[r] * fact[n - r];
}

// O(k)
Mint comb_slow(ll n, ll k) {
    if (n < 0 || k < 0 || k > n) return Mint(0);
    Mint res = ifact[k];
    for (int i = 0; i < k; ++i) {
        res = res * (n - i);
    }
    return res;
}

// line up
// a 'o' + b 'x'
Mint comb2(int a, int b) {
    if (a < 0 || b < 0) return 0;
    return comb(a + b, a);
}

// divide a into b groups
Mint nhr(int a, int b) {
    if (b == 0) return Mint(a == 0);
    return comb(a + b - 1, a);
}

// O(p + log_p n)

Mint lucas(ll n, ll k, int p) {
    if (n < 0 || k < 0 || k > n) return Mint(0);
    Mint res = 1;
    while (n > 0) {
        res *= comb(n % p, k % p);
        n /= p;
        k /= p;
    }
    return res;
}

struct ModPrepare {
    ModPrepare() { mod_init(); }
} prep_mod;

void slv() {
    int n;
    cin >> n;

    V<Mint> dp(n + 1), dp2(n + 1);
    dp[0] = 1;
    dp2[0] = dp2[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 2] * (i - 1) * 2;
        dp2[i] = dp2[i - 1] + dp2[i - 2] * (i - 1);
    }

    Mint ans;

    for (int k = 0; k * 2 <= n; ++k) {
        int rem = n - k * 2;
        Mint coef = comb(rem + k, k);
        ans += coef * dp[k] * dp2[rem];
    }

    show(ans);
}

int main() {
    int cases = 1;
    cin >> cases;
    rep(i, cases) slv();

    return 0;
}