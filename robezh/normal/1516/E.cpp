#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = (int)1e9 + 7;
const int N = 405;

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


mi fac[N], facinv[N];

mi choose(int n, int k) {
    return fac[n] * facinv[k] * facinv[n - k];
}

mi bchoose(int n, int k) {
    mi res = 1;
    rep(i, n - k + 1, n + 1) res *= i;
    return res * facinv[k];
}

//mi dp[N][N][N];

int n, k;
mi ksum[N];
mi st[N][N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) {
        fac[i] = fac[i - 1] * i;
    }
    facinv[N - 1] = inv(fac[N - 1]);
    for(int i = N - 2; i >= 0; i--) {
        facinv[i] = facinv[i + 1] * (i + 1);
    }
    cin >> n >> k;

    st[0][0] = 1;
    rep(i, 1, min(n + 1, N)) {
        rep(j, 1, i + 1) {
            st[i][j] = st[i - 1][j - 1] + (i - 1) * st[i - 1][j];
        }
    }
    rep(i, 1, min(n + 1, N)) {
        rep(j, 1, i + 1) {
            for(int ones = 1; ones <= i && ones <= j; ones++) {
                st[i][j] -= choose(i, ones) * st[i - ones][j - ones];
            }
            ksum[i - j] += st[i][j] * bchoose(n, i);

        }

    }
    ksum[0] = 1;
    rep(i, 1, k + 1) {
        if(i >= 2) ksum[i] += ksum[i - 2];
        cout << int(ksum[i]) << " ";
    }

}