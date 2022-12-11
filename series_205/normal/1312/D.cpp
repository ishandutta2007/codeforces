#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

template <int M> class ModInt {
    int x;

  public:
    constexpr ModInt() : x(0) {}
    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}
    constexpr ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &p) {
        if((x += M - p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % M);
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    constexpr ModInt operator-() const { return ModInt(-x); }
    constexpr ModInt operator+(const ModInt &p) const {
        return ModInt(*this) += p;
    }
    constexpr ModInt operator-(const ModInt &p) const {
        return ModInt(*this) -= p;
    }
    constexpr ModInt operator*(const ModInt &p) const {
        return ModInt(*this) *= p;
    }
    constexpr ModInt operator/(const ModInt &p) const {
        return ModInt(*this) /= p;
    }
    constexpr bool operator==(const ModInt &p) const { return x == p.x; }
    constexpr bool operator!=(const ModInt &p) const { return x != p.x; }
    constexpr ModInt inverse() const {
        int a = x, b = M, u = 1, v = 0, t = 0;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    constexpr ModInt pow(const int64_t &n) const {
        ModInt ret(1), mul(x);
        int64_t k = n % (M - 1);
        while(k > 0) {
            if(k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
    constexpr friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    constexpr friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t = 0;
        is >> t;
        a = ModInt(t);
        return (is);
    }
};
using modint = ModInt<Mod>;

// 
vector<modint> fact, fact_inv;

void COMinit(const ll &MAX) {
    fact.resize(MAX + 1);
    fact_inv.resize(MAX + 1);
    fact[0] = 1;
    rep(i, MAX) fact[i + 1] = fact[i] * (i + 1);
    fact_inv[MAX] = fact[MAX].inverse();
    for(int i = MAX; i; i--)
        fact_inv[i - 1] = fact_inv[i] * i;
}

modint COM(const ll &n, const ll &k) {
    if(n < k || k < 0) return 0;
    return fact[n] * fact_inv[k] * fact_inv[n - k];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    COMinit(m);
    modint ans = COM(m, n - 1) * COM(n - 2, 1);
    ans *= modint(2).pow(n);
    ans /= modint(2).pow(3);
    cout << ans << endl;

    return 0;
}