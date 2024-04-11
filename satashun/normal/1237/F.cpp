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
    static uint get_mod() { return MOD; }
};

using Mint = ModInt<998244353>;

const int maxv = 10010;

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

const int MX = 3700;
Mint dph[MX][MX], dpw[MX][MX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    init();

    int h, w, n;
    cin >> h >> w >> n;

    V<bool> frh(h, true), frw(w, true);

    rep(i, n) {
        rep(j, 2) {
            int r, c;
            cin >> r >> c;
            --r, --c;
            frh[r] = frw[c] = false;
        }
    }

    dph[0][0] = 1;

    rep(i, h) {
        rep(j, MX) {
            if (dph[i][j] == 0) continue;
            dph[i + 1][j] += dph[i][j];
            if (i + 1 < h && frh[i] && frh[i + 1]) {
                dph[i + 2][j + 1] += dph[i][j];
            }
        }
    }

    dpw[0][0] = 1;

    rep(i, w) {
        rep(j, MX) {
            if (dpw[i][j] == 0) continue;
            dpw[i + 1][j] += dpw[i][j];
            if (i + 1 < w && frw[i] && frw[i + 1]) {
                dpw[i + 2][j + 1] += dpw[i][j];
            }
        }
    }

    int cnth = 0, cntw = 0;
    rep(i, h) if (frh[i]) cnth++;
    rep(i, w) if (frw[i]) cntw++;

    Mint ans;
    rep(i, MX) {
        rep(j, MX) {
            if (dph[h][i] == 0 || dpw[w][j] == 0) continue;
            Mint coef = comb(cnth - i * 2, j) * comb(cntw - j * 2, i) *
                        fact[i] * fact[j];
            ans += dph[h][i] * dpw[w][j] * coef;
            // debug(i, j, dph[h][i], dpw[w][j], coef);
        }
    }
    cout << ans << endl;

    return 0;
}