#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;
const int mod = (int)1e9 + 7, inv2 = (mod + 1) / 2;
const int MOD = (int)1e9 + 7;

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

int n, m, x;

void solve_2() {
    vector<vector<mi>> dp(n + 1, vector<mi>(n + 1, 0));
    auto ndp = dp;
    for(auto &v : ndp) fill(all(v), mi(0));

    ndp[0][0] = 1;
    for (int pos = m - 1; pos >= 0; pos--) {
        ndp.swap(dp);
        for(auto &v : ndp) fill(all(v), mi(0));
        for (int st = 0; st <= n; st++) {
            for (int ed = 0; ed <= st; ed++) {
                if(pos != x) ndp[st][ed] += dp[st][ed];
                if(st && pos != x) ndp[st][ed] += dp[st - 1][ed];
                if(ed) ndp[st][ed] += dp[st][ed - 1];
                if(st && ed) ndp[st][ed] += dp[st - 1][ed - 1];
            }
        }
    }
    mi res = ndp[n][n];
    rep(i, 1, n + 1) res *= i;
    cout << int(res) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    x--;

    if(m < n) {
        cout << 0 << endl;
    } else {
        solve_2();
    }

}