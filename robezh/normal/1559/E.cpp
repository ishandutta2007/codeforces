#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)55;


const int MOD = 998244353;

struct mi {
    typedef decay<decltype(MOD)>::type T;
    /// don't silently convert to T
    T v; explicit operator T() const { return v; }
    mi() { v = 0; }
    mi(ll _v) {
        v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
        if (v < 0) v += MOD;
    }
    friend bool operator==(const mi& a, const mi& b) {
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) {
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) {
        return a.v < b.v; }
//    friend void re(mi& a) { ll x; re(x); a = mi(x); }
//    friend str ts(mi a) { return ts(a.v); }

    mi& operator+=(const mi& m) {
        if ((v += m.v) >= MOD) v -= MOD;
        return *this; }
    mi& operator-=(const mi& m) {
        if ((v -= m.v) < 0) v += MOD;
        return *this; }
    mi& operator*=(const mi& m) {
        v = (ll)v*m.v%MOD; return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return pow(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

const int M = (int)1e5 + 50;
struct P {
    int l, r;
} p[N];

int n, m;
mi dp[N][M];
mi res[M];

mi get(mi a[], int x) {
    return x < 0 ? mi(0) : a[x];
}

void solve(int d) {
    for (int i = 0; i <= m / d; i++) dp[0][i] = 1;
    for(int i = 1; i <= n; i++) {
        int l = (p[i].l - 1) / d + 1, r = (p[i].r) / d;
        for (int j = 0; j <= m / d; j++) {
            mi sdp = get(dp[i - 1], j - l) - get(dp[i - 1], j  - r - 1);
//            cout << i << " " << l << " " << r << " " << j << endl;
            dp[i][j] = sdp + get(dp[i], j - 1);
        }
    }
    res[d] = dp[n][m / d];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 1, n + 1) cin >> p[i].l >> p[i].r;
    for (int i = m; i >= 1; i--) {
        solve(i);
//        cout << i << " " << int(res[i]) << endl;
        for (int j = 2 * i; j <= m; j += i) res[i] -= res[j];
    }
    cout << int(res[1]) << '\n';

}