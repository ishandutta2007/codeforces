#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = (int)1e9 + 7, N = (int)2e5 + 50;

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

int n, a[N];

mi fac[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;

    cin >> n;
    ll sum = 0;
    rep(i, 0, n) cin >> a[i], sum += a[i];
    if(sum % n != 0) {
        cout << 0 << endl;
        return 0;
    }
    int tar = int(sum / n);
    int cntl = 0, cntr = 0, cnte = 0;
    map<int, int> ml, mr;
    rep(i, 0, n) {
        if(a[i] < tar) cntl++, ml[a[i]]++;
        else if(a[i] == tar) cnte++;
        else cntr++, mr[a[i]]++;
    }
    mi res;
    if(cntl == 0 || cntr == 0) {
        res = fac[cntl] * fac[cntr];
    } else if(cntl == 1 || cntr == 1 ){
        res = fac[cntl + cntr];
    } else {
        res = 2 * fac[cntl] * fac[cntr];
    }
    for(auto e : ml) res /= fac[e.second];
    for(auto e : mr) res /= fac[e.second];

    rep(i, cntl + cntr + 1, n + 1) res *= i;
    res /= fac[cnte];

    cout << int(res) << '\n';
}