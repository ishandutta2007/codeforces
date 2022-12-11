#include <bits/stdc++.h>
// #include <atcoder/all>
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
using mint = ModInt<mod>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) {
        cin >> v[i];
        v[i]--;
    }

    vector<int> s;
    rep(i, n) if(v[i] != -1) {
        int x = i;
        int cnt = 0;
        while(v[x] != -1) {
            cnt++;
            int nxt = v[x];
            v[x] = -1;
            x = nxt;
        }
        s.push_back(cnt);
    }

    mint cost = mint(3).pow(n / 3);

    if(n % 3 == 0) {
        cout << cost << " ";
        int ans = 0;
        rep(i, s.size()) {
            ans += (s[i] - 1) / 3;
            s[i] %= 3;
        }
        int a = count(ALL(s), 1), b = count(ALL(s), 2);
        int c = min(a, b);
        ans += c;
        a -= c;
        b -= c;
        ans += a / 3 * 2;
        ans += b;
        cout << ans << "\n";
    } else if(n % 3 == 2) {
        cout << cost * 2 << " ";
        int ans = 0;
        rep(i, s.size()) {
            ans += (s[i] - 1) / 3;
            s[i] %= 3;
        }
        int a = count(ALL(s), 1), b = count(ALL(s), 2);
        if(b) {
            b--;
        } else {
            a -= 2;
            ans++;
        }
        int c = min(a, b);
        ans += c;
        a -= c;
        b -= c;
        ans += a / 3 * 2;
        ans += b;
        cout << ans << "\n";
    } else {
        cout << cost / 3 * 4 << " ";
        int ans = 0;
        rep(i, s.size()) {
            while(s[i] > 4) {
                s[i] -= 3;
                ans++;
            }
        }
        int a = count(ALL(s), 1), b = count(ALL(s), 2), c = count(ALL(s), 4);
        // cerr << a << " " << b << " " << c << endl;
        while(c && b - 2 > a) {
            c--;
            a++;
            ans++;
        }
        if(c) {
            c--;
            a += c;
            ans += c;
        } else if(a + b * 2 < 4) {
            ans++;
            a--;
        } else {
            rep(i, 2) {
                if(b)
                    b--;
                else {
                    a -= 2;
                    ans++;
                }
            }
        }
        c = min(a, b);
        assert(c >= 0);
        ans += c;
        a -= c;
        b -= c;
        ans += a / 3 * 2;
        ans += b;
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}