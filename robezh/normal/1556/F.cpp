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

const int N = 15, M = (1 << 14) + 5;


map<vi, int> mp;

void pre(vi vs) {

}

int n, a[N];
int bcnt[M];
vi bt[M];
mi win[N][N];
//mi dp[M], rs[M];
mi dp[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        rep(j, 0, n) {
            win[i][j] = mi(a[i]) / (mi(a[i]) + mi(a[j]));
        }
    }
    rep(i, 1, 1 << n) bcnt[i] = bcnt[i / 2] + (i & 1);
    rep(mask, 0, 1 << n) {
        rep(b, 0, n) if(mask >> b & 1) bt[mask].push_back(b);
    }
    mi fres = 0;
    rep(mask, 1, 1 << n) {
        dp[mask] = 1;
        for(int sub = mask; ; sub = (sub - 1) & mask) {
            if(sub == mask) continue;
            int rem = mask ^ sub;
            mi s = dp[sub];
            for(int b : bt[sub]) {
                for(int r : bt[rem]) {
                    s *= win[b][r];
                }
            }
            dp[mask] -= s;
            if(sub == 0) break;
        }

        mi s = dp[mask];
        int rem = ((1 << n) - 1) ^ mask;
        for(int b : bt[mask]) {
            for(int r : bt[rem]) {
                s *= win[b][r];
            }
        }
        fres += s * bcnt[mask];

    }

    cout << int(fres) << '\n';
}