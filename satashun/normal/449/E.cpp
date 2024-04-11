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

using Mint = ModInt<1000000007>;
const Mint i3 = (Mint::get_mod() + 1) / 3;

const int maxn = 1000010;
Mint ps0[maxn], ps1[maxn], ps2[maxn];

// for factorize
int pr[maxn], tot[maxn];

void sieve() {
    memset(pr, -1, sizeof(pr));
    for (int i = 1; i < maxn; ++i) {
        tot[i] = i;
    }

    for (int i = 2; i < maxn; ++i) {
        if (pr[i] == -1) {
            tot[i] = i - 1;
            for (int j = i * 2; j < maxn; j += i) {
                pr[j] = i;
                tot[j] = tot[j] / i * (i - 1);
            }
        }
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    sieve();

    for (int i = 1; i < maxn; ++i) {
        Mint d(i);
        Mint v = d * (d + 1) * (d * 2 + 1) * i3 - d * d * 3;
        Mint gs = 0;

        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                gs += tot[i / j] * j;
                if (j * j != i) {
                    gs += tot[j] * (i / j);
                }
            }
        }
        gs *= 2;
        v += gs;
        ps0[i] = ps0[i - 1] + v;
        ps1[i] = ps1[i - 1] + v * i;
        ps2[i] = ps2[i - 1] + v * i * i;
    }

    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        if (n > m) swap(n, m);
        Mint ans = ps0[n] * (n + 1) * (m + 1) - ps1[n] * (n + m + 2) + ps2[n];
        cout << ans << '\n';
    }
    return 0;
}