#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353, N = (int)2e5 + 50;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
    friend mi fp(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mi inv(const mi& a) { assert(a.v != 0);
        return fp(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

vector<mi> fac, facinv;

mi C(int n, int k) {
    return fac[n] * facinv[n - k] * facinv[k];
}

int main() {
    fac.push_back(1);
//    cout << fac.back().v << endl;
    while(sz(fac) < N) fac.push_back(fac.back() * sz(fac));
    while(sz(facinv) < N) facinv.push_back(inv(fac[sz(facinv)]));
    int n, k;
    cin >> n >> k;
    mi res = 0;
    int c = n - k;
    if(c < 0) return cout << 0 << endl, 0;
    mi s = 1;
    for(int i = 0; i <= c; i++) {
        res += s * C(c, i) * fp(mi(c - i), n);
        s *= -1;
    }
    if(k != 0) res *= 2 * C(n, c);
    cout << res.v << endl;
}