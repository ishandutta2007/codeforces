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
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &x : v) is >> x;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i];
    return os;
}
struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
/*-------------------------------------------*/

template <int M>
class ModInt {
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
using mint = ModInt<Mod>;

vector<mint> f{1}, iv{1};
mint fact(int n) {
    assert(0 <= n);
    int sz = f.size();
    if(sz <= n) {
        f.resize(n * 2);
        iv.resize(n * 2);
        for(int i = sz; i < n * 2; i++) f[i] = f[i - 1] * i;
        iv[n * 2 - 1] = f[n * 2 - 1].inverse();
        for(int i = n * 2 - 1; i > sz; i--) iv[i - 1] = iv[i] * i;
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
mint H(int n, int k) { return C(n + k - 1, k); }

int main() {
    int n;
    cin >> n;
    string input;
    int cnt[2][2]{};
    int cntBoth = 0;
    rep(i, n) {
        cin >> input;
        for(int j : {0, 1})
            for(int c : {0, 1})
                if(input[j] == "BW"[c]) cnt[j][c]++;
        if(cntBoth != -1 && input == "??")
            cntBoth++;
        else if(input[0] == input[1])
            cntBoth = -1;
    }

    mint ans = 0;
    rep(b, n + 1) {
        ans += C(n - cnt[0][0] - cnt[0][1], b - cnt[0][0]) *
               C(n - cnt[1][0] - cnt[1][1], b - cnt[1][1]);
    }

    if(cntBoth != -1) {
        ans -= mint(2).pow(cntBoth);
        if(cnt[0][0] + cnt[1][1] == 0) ans += 1;
        if(cnt[0][1] + cnt[1][0] == 0) ans += 1;
    }

    cout << ans << endl;
}