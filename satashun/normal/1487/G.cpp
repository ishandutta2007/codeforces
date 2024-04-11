//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }
    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    friend istream& operator>>(istream& in, M& x) {
        ll v_;
        in >> v_;
        x = M(v_);
        return in;
    }
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;

const int maxv = 1000010;

V<Mint> fact(maxv), ifact(maxv), inv(maxv);

void init() {
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

const int B = 26;
const int MX = 401;

Mint dp[2][MX][MX][3][3];
Mint ep[2][MX][2][2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    V<int> c(B);
    rep(i, B) cin >> c[i];

    Mint ans = 1;

    rep(i, n) {
        if (i < 2)
            ans *= 26;
        else
            ans *= 25;
    }

    int p = 0, q = 1;

    dp[p][0][0][0][0] = 1;
    per(i, n) {
        rep(j, MX) {
            for (int k = 0; k + j < MX; ++k) {
                rep(l, 3) rep(m, 3) { dp[q][j][k][l][m] = 0; }
            }
        }
        rep(j, MX) {
            for (int k = 0; k + j < MX; ++k) {
                rep(l, 3) rep(m, 3) {
                    if (dp[p][j][k][l][m] == 0) continue;
                    if (!(i < n - 2 && m == 0)) {
                        dp[q][j + 1][k][0][l] += dp[p][j][k][l][m];
                    }
                    if (!(i < n - 2 && m == 1)) {
                        dp[q][j][k + 1][1][l] += dp[p][j][k][l][m];
                    }
                    int co = 24;
                    if (i < n - 2 && m == 2) co--;
                    dp[q][j][k][2][l] += dp[p][j][k][l][m] * co;
                }
            }
        }

        swap(p, q);
    }

    p = 0, q = 1;

    ep[p][0][0][0] = 1;
    per(i, n) {
        rep(j, MX) {
            rep(l, 2) rep(m, 2) { ep[q][j][l][m] = 0; }
        }

        rep(j, MX) {
            rep(l, 2) {
                rep(m, 2) {
                    if (ep[p][j][l][m] == 0) continue;
                    if (!(i < n - 2 && m == 0)) {
                        ep[q][j + 1][0][l] += ep[p][j][l][m];
                    }
                    int co = 25;
                    if (i < n - 2 && m == 1) co--;
                    ep[q][j][1][l] += ep[p][j][l][m] * co;
                }
            }
        }
        swap(p, q);
    }

    rep(a, 26) {
        for (int j = c[a] + 1; j <= n; ++j) {
            rep(l, 2) rep(m, 2) ans -= ep[p][j][l][m];
        }
    }

    rep(a, 26) {
        rep(b, a) {
            for (int j = c[a] + 1; j <= n; ++j) {
                for (int k = c[b] + 1; k <= n; ++k) {
                    rep(l, 3) rep(m, 3) { ans += dp[p][j][k][l][m]; }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}