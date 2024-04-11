#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
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

const int N = 1005;
int n, m;
string s, t;
mi dp[N][N][2];
int sla[N], tla[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    n = s.length(), m = t.length();
    s = " " + s, t = " " + t;
    sla[1] = tla[1] = 1;
    rep(i, 2, n + 1) sla[i] = (s[i] == s[i - 1] ? i : sla[i - 1]);
    rep(i, 2, m + 1) tla[i] = (t[i] == t[i - 1] ? i : tla[i - 1]);
    mi res = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            dp[i][j][0] += dp[i - 1][j][0] * (s[i] != s[i - 1]);
            dp[i][j][0] += (dp[i - 1][j][1] + (j - tla[j] + 1)) * (s[i] != t[j]);

            dp[i][j][1] += dp[i][j - 1][1] * (t[j] != t[j - 1]);
            dp[i][j][1] += (dp[i][j - 1][0] + (i - sla[i] + 1)) * (s[i] != t[j]);
//            cout << i << " " << j << " " << int(dp[i][j][0] + dp[i][j][1]) << endl;
            res += dp[i][j][0] + dp[i][j][1];
        }
    }
    cout << int(res) << endl;

}