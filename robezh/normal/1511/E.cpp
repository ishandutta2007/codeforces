#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)3e5 + 50;

const int MOD = (int)998244353;

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


int n, m;
string str[N];
vector<vector<mi>> dp;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    mi inv4 = inv(mi(4));
    mi inv2 = inv(mi(2));
    rep(i, 0, n) cin >> str[i];
    dp = vector<vector<mi>>(n, vector<mi>(m, 0));
    mi res = 0;
    int cntw = 0;


    rep(i, 0, n) {
        rep(j, 0, m) {
            cntw += (str[i][j] == 'o');

            if(str[i][j] == '*' || j == 0 || str[i][j - 1] == '*') dp[i][j] = 0;
            else {
                dp[i][j] = inv4;
                if(j >= 2) {
                    dp[i][j] += dp[i][j - 2] * inv4;
                }
                res += dp[i][j] * ((j + 1 < m && str[i][j + 1] == 'o') ? inv2 : 1);
            }
        }
    }
    rep(j, 0, m) {
        rep(i, 0, n) {
            if(str[i][j] == '*' || i == 0 || str[i - 1][j] == '*') dp[i][j] = 0;
            else {
                dp[i][j] = inv4;
                if(i >= 2) {
                    dp[i][j] += dp[i - 2][j] * inv4;
                }
                res += dp[i][j] * ((i + 1 < n && str[i + 1][j] == 'o') ? inv2 : 1);
            }
        }
    }
    cout << int(res * pow(mi(2), cntw)) << '\n';


}