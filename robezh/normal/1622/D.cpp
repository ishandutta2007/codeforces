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
typedef pair<ll, int> pli;
typedef vector<int> vi;

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

const int N = 5005;

int n, k;
string str;
mi fac[N], facinv[N];

mi C(int a, int b) {
    if(a < 0 || b < 0 || a - b < 0) return 0;
//    cout << a << " choose " << b << endl;
    return fac[a] * facinv[b] * facinv[a - b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = facinv[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i, facinv[i] = facinv[i - 1] / i;

    cin >> n >> k;
    cin >> str;
    int r = -1, cntk = 0;
    int tot = 0;
    for (char c : str) tot += c == '1';
    mi res = 1;
    if(tot <  k) {
        cout << 1 << endl;
        return 0;
    }
    rep(i, 0, n) {
        while(r + 1 < n && (cntk + (str[r + 1] - '0') <= k)) {
            r++;
            cntk += (str[r] - '0');
        }
//        cout << i << " " << r << " " << cntk << endl;
        if(str[i] == '0') {
            res += C(r - i, cntk - 1);
//            cout << "choose " << r - i << " " <
        }
        if(str[i] == '1') {
            res += C(r - i, cntk);
        }
        cntk -= (str[i] - '0');
    }
    cout << int(res) << endl;
}