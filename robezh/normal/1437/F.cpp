#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
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

const int N = 2 * 5005;
mi fac[N], facinv[N];

mi upow(int n, int k) {
    return fac[n + k - 1] * facinv[n - 1];
}

int n, a[N];
int to[N];
mi dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = facinv[0] = 1;
    for(int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i;
        facinv[i] = inv(fac[i]);
    }
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(a[n - 1] * 2 > a[n]) return cout << 0 << endl, 0;

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        while(cur < i && a[cur] * 2 <= a[i]) cur++;
        to[i] = cur;
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int la = 0; la < to[i]; la++) {
            dp[i] += dp[la] * upow(n - to[i] + 1, to[i] - to[la] - 1);
//            cout << i << ": " << int(dp[i]) << endl;
        }

    }
    cout << int(dp[n]) << '\n';




}