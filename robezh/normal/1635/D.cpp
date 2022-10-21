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
typedef pair<int, int> P;
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

const int N = (int)2e5 + 50;

int n, p;
int a[N];

map<int, int> vis;
mi dp[N], sdp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;
    dp[0] = sdp[0] = 1;
    rep(i, 1, N) {
        dp[i] += dp[i - 1];
        if(i >= 2) dp[i] += dp[i - 2];
        sdp[i] = sdp[i - 1] + dp[i];
    }
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    mi res = 0;
    rep(i, 0, n) {
        int len = 0;
        int x = a[i];
        while(x) len++, x /= 2;
        x = a[i];
        bool found = false;
        while(x > 1 && (x % 2 == 1 || x % 4 == 0)) {
            if(x % 2 == 1) x /= 2;
            else x /= 4;
            found |= (vis.find(x) != vis.end());
        }
        if(!found) {
            vis[a[i]] = 1;
            if(len <= p) res += sdp[p - len];
        }
    }
//    for (auto x : vis) cout << x.first << endl;
    cout << int(res) << '\n';

}