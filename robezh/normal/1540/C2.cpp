#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 105;

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


int n;
int c[N], b[N];
int lb[N], psum[N];
mi dp[N][N * N], sdp[N][N * N];
mi prod;

map<int, mi> res;

mi solve(int x) {
    if(n * x + psum[n] > n * 100) return 0;
    if(n * x + psum[n] <= 0) return prod;
    if(res.count(x)) return res[x];

    dp[0][0] = 1;
    int maxs = 100 * n;
    rep(i, 0, maxs + 1) sdp[0][i] = 1;
    rep(i, 1, n + 1) {
        rep(s, 0,  maxs + 1) {
            dp[i][s] = 0;
            if(s >= psum[i] + i * x) {
                dp[i][s] = sdp[i - 1][s];
                if(s - c[i] > 0) dp[i][s] -= sdp[i - 1][s - c[i] - 1];
            }
            sdp[i][s] = dp[i][s];
            if(s) sdp[i][s] += sdp[i][s - 1];
        }
    }

//    rep(i, 1, n + 1) {
//        rep(s, psum[i] + (i - 1) ,  maxs + 1) {
//            rep(cur, 0, min(s + 1, c[i] + 1)) {
//                dp[i][s] += dp[i - 1][s - cur];
//            }
//        }
//    }
//    mi res = 0;
//    rep(i, 0, maxs + 1) res += dp[n][i];
    mi rs = 0;
    rep(i, 0, maxs + 1) rs += dp[n][i];
    return res[x] = rs;
}

//mt19937 rng(2333);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    prod = 1;
    rep(i, 1, n + 1) cin >> c[i], prod *= (c[i] + 1);
    rep(i, 1, n) cin >> b[i];
    rep(i, 2, n + 1) {
        lb[i] = lb[i - 1] + b[i - 1];
        psum[i] = lb[i] + psum[i - 1];
    }
    int q;
    cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << int(solve(x)) << '\n';
    }


}