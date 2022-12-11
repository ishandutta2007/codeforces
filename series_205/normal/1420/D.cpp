// #include <atcoder/all>
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

template <int M> class ModInt {
    int x;

  public:
    constexpr ModInt() : x(0) {}
    constexpr ModInt(int64_t y) : x(y >= 0 ? y % M : (M - (-y) % M) % M) {}
    constexpr ModInt &operator+=(const ModInt p) {
        if((x += p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt p) {
        if((x += M - p.x) >= M) x -= M;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt p) {
        x = (int)(1LL * x * p.x % M);
        return *this;
    }
    constexpr ModInt &operator/=(const ModInt p) {
        *this *= p.inverse();
        return *this;
    }
    constexpr ModInt operator-() const { return ModInt(-x); }
    constexpr ModInt operator+(const ModInt p) const {
        return ModInt(*this) += p;
    }
    constexpr ModInt operator-(const ModInt p) const {
        return ModInt(*this) -= p;
    }
    constexpr ModInt operator*(const ModInt p) const {
        return ModInt(*this) *= p;
    }
    constexpr ModInt operator/(const ModInt p) const {
        return ModInt(*this) /= p;
    }
    constexpr bool operator==(const ModInt p) const { return x == p.x; }
    constexpr bool operator!=(const ModInt p) const { return x != p.x; }
    constexpr ModInt inverse() const {
        int a = x, b = M, u = 1, v = 0, t = 0;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    constexpr ModInt pow(int64_t k) const {
        ModInt ret(1), mul(x);
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
using mint = ModInt<998244353>;

vector<mint> f{1}, iv{1};
mint fact(int n) {
    assert(0 <= n);
    int sz = f.size();
    if(sz <= n) {
        f.resize(n * 2);
        iv.resize(n * 2);
        for(int i = sz; i < n * 2; i++)
            f[i] = f[i - 1] * i;
        iv[n * 2 - 1] = f[n * 2 - 1].inverse();
        for(int i = n * 2 - 1; i > sz; i--)
            iv[i - 1] = iv[i] * i;
    }
    return f[n];
}
mint fact_inv(int n) {
    fact(n);
    return iv[n];
}

mint P(int n, int k) {
    if(n < k || k < 0) return 0;
    return fact(n) * fact_inv(n - k);
}
mint C(int n, int k) {
    if(n < k || k < 0) return 0;
    return fact(n) * fact_inv(k) * fact_inv(n - k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>> mp;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        mp[l].first++;
        mp[r].second++;
    }

    mint ans = 0;
    int cnt = 0;
    for(auto [key, p] : mp) {
        cnt += p.first;
        ans += C(cnt, k) - C(cnt - p.first, k);
        cnt -= p.second;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}