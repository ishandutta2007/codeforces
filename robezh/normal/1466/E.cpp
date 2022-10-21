#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50 ,mod = (int)1e9 + 7;

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
ll a[N];
mi s[N];
ll cnt[60][2];
mi s2[60];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));

        rep(i, 0, n) {
            cin >> a[i];
            rep(b, 0, 60) cnt[b][(a[i] >> b & 1)]++;
        }
        fill(s2, s2 + 60, 0);
        rep(i, 0, n) {
            mi cs;
            rep(b, 0, 60) {
                if(!(a[i] >> b & 1)) cs += mi(cnt[b][0]) * mi(1LL << b);
            }
            rep(b, 0, 60) {
                if(a[i] >> b & 1) s2[b] += cs;
            }
        }
        mi res = 0;
        rep(b1, 0, 60) {
            rep(b2, 0, 60) {
                res += mi(cnt[b1][1]) * cnt[b1][1] * n * mi(1LL << b1) * mi(1LL << b2);
            }
        }
        rep(b1, 0, 60) {
            res -= cnt[b1][1] * mi(1LL << b1) * s2[b1];
        }
        cout << int(res) << '\n';
    }


}