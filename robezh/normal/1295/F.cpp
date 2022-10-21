#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 105, INF = (int)1e9;

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

mi fac[N];

mi choose(int n, int k) {
    mi res = 1;
    for(int i = n; i > n - k; i--) res *= i;
    res /= fac[k];
    return res;
}

mi star_and_bar(int n, int k) {
    if(k == 0) return 1;
//    if(n == 1) return 1;
    return choose(n + k - 1, k);
}

int n;
int lb[N], rb[N];
int mxlb[N][N], mnrb[N][N];
mi dp[N][N];

vi pts;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;

    mi res = 1;
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> lb[i] >> rb[i];
        pts.push_back(lb[i]);
        pts.push_back(rb[i] + 1);
        res /= (rb[i] - lb[i] + 1);
    }
    sort(all(pts));
    pts.resize(unique(all(pts)) - pts.begin());
    rep(i, 1, n + 1) {
        rep(j, i, n + 1) {
            mxlb[i][j] = -1;
            mnrb[i][j] = INF;
            rep(k, i, j + 1) {
                mxlb[i][j] = max(mxlb[i][j], lb[k]);
                mnrb[i][j] = min(mnrb[i][j], rb[k]);
            }
        }
    }

    dp[sz(pts)][0] = 1;
    for(int i = sz(pts) - 1; i >= 1; i--) {
        rep(j, 0, n + 1) {
            for(int take = 0; take <= j; take++) {
                if(take && (mxlb[j - take + 1][j] > pts[i - 1] || mnrb[j - take + 1][j] + 1 < pts[i])) continue;
                dp[i][j] += dp[i + 1][j - take] * star_and_bar(pts[i] - pts[i - 1], take);
            }
        }
    }
    res *= dp[1][n];
    cout << int(res) << endl;


}