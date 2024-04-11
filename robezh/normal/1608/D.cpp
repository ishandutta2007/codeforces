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


const int N = (int)1e5 + 50;


mi fac[N], facinv[N];
int n;
string str[N];
int lc[3], rc[3];

mi C(int n, int k) {
    return fac[n] * facinv[k] * facinv[n - k];
}

mi geteq() {
    mi res = 1;
    rep(i, 0, n) {
        if(str[i][0] == '?' && str[i][1] == '?') res *= 2;
        else if(str[i][0] != '?' && str[i][1] != '?') {
            if(str[i][0] != str[i][1]) return 0;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);
    assert(fac[5] * facinv[5] == 1);

    cin >> n;
    rep(i, 0, n) {
        cin >> str[i];
        if(str[i][1] != '?') {
            str[i][1] = 'W' + 'B' - str[i][1];
            rc[str[i][1] == 'W']++;
        }
        if(str[i][0] != '?') {
            lc[str[i][0] == 'W']++;
        }
    }
    lc[2] = n - lc[0] - lc[1];
    rc[2] = n - rc[0] - rc[1];
    mi res = 0;
    for (int cnt0 = max(rc[0], lc[0]); n - cnt0 >= max(rc[1], lc[1]); cnt0++) {
        res += C(lc[2], cnt0 - lc[0]) * C(rc[2], cnt0 - rc[0]);
    }
    res -= geteq();
    if(rc[0] == 0 && lc[0] == 0) res += 1;
    if(rc[1] == 0 && lc[1] == 0) res += 1;
    cout << int(res) << endl;



}