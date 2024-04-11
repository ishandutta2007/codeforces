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

void init() {
    const int maxv = 1000010;
    fact.resize(maxv);
    ifact.resize(maxv);
    inv.resize(maxv);

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
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return fact[n] * ifact[r] * ifact[n - r];
}

// O(k)

Mint comb_slow(ll n, ll k) {
    Mint res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) * inv[i + 1];
    }
    return res;
}

// line up
// a 'o' + b 'x'
Mint comb2(int a, int b) {
    if (a < 0 || b < 0) return 0;
    return comb(a + b, a);
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

void slv() {
    int n;
    cin >> n;
    auto a = make_vec<int>(n * 2, n);
    rep(i, n * 2) {
        rep(j, n) {
            cin >> a[i][j];
            --a[i][j];
        }
    }

    Mint ans = 1;

    V<int> inds;
    V<int> used(n * 2);
    auto rem = make_vec<int>(n, n);
    rep(i, n * 2) {
        rep(j, n) { rem[j][a[i][j]]++; }
    }

    auto del = [&](int r) {
        used[r] = 1;
        rep(j, n) { rem[j][a[r][j]]--; }
    };

    rep(t, n) {
        bool fd = 0;
        rep(i, n * 2) {
            if (fd) break;
            if (!used[i]) {
                rep(j, n) {
                    if (rem[j][a[i][j]] == 1) {
                        del(i);
                        rep(r, n * 2) {
                            rep(p, n) {
                                if (!used[r] && a[r][p] == a[i][p]) {
                                    del(r);
                                    break;
                                }
                            }
                        }
                        inds.pb(i);
                        fd = 1;
                        break;
                    }
                }
            }
        }
        if (!fd) {
            ans *= 2;
            rep(i, n * 2) {
                if (!used[i]) {
                    inds.pb(i);
                    rep(r, n * 2) {
                        rep(p, n) {
                            if (!used[r] && a[r][p] == a[i][p]) {
                                del(r);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
    rep(i, n) { cout << inds[i] + 1 << (i == n - 1 ? '\n' : ' '); }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    init();
    int tc;
    cin >> tc;
    while (tc--) {
        slv();
    }
    return 0;
}