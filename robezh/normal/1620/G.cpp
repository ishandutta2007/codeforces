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
const int N = (int)1e5 + 50, INF = (int)1e9;

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

int n;
int cnt[26][26];
int mn[(1 << 23)][26];
mi dp[(1 << 23)];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        string str;
        cin >> str;
        for (char c : str) cnt[i][c - 'a'] += 1;
    }
    rep(i, 0, (1 << n)) fill(mn[i], mn[i] + 26, INF);
    rep(i, 1, (1 << n)) {
        int b = 0;
        while(!(i >> b & 1)) b++;
        rep(j, 0, 26) {
            mn[i][j] = min(mn[i ^ (1 << b)][j], cnt[b][j]);
        }
    }
    rep(i, 1, (1 << n)) {
        mi prod = 1;
        rep(j, 0, 26) prod *= (mn[i][j] + 1);
        if(__builtin_popcount(i) % 2 == 1) {
//            cout << "adding " << bitset<10>(i) << " " << int(prod) << endl;
            dp[i] += prod;
        }
        else {
//            cout << "adding " << bitset<10>(i) << " -" << int(prod) << endl;
            dp[i] -= prod;
        }
    }
    rep(b, 0, n) {
        rep(i, 0, (1 << n)) {
            if(i >> b & 1) dp[i] += dp[i ^ (1 << b)];
        }
    }
//    rep(i, 0, (1 << n)) {
//        cout << bitset<10>(i) << " has sub" << int(dp[i]) << endl;
//
//    }

    ll res = 0;
    rep(i, 1, (1 << n)) {
        int c0 = 0, c1 = 0;
        rep(b, 0, n) {
            c0 += (i >> b & 1);
            c1 += (i >> b & 1) * (b + 1);
        }
        res ^= (ll)((int)(dp[i])) * c0 * c1;
    }
    cout << res << endl;


}