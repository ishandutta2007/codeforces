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
const int N = 405;

int n;
int c[26];
mi dp2[2][N][N][3];
mi dp1[2][N][2];
mi dp0[2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, 26) cin >> c[i];

    int nw = 0, la = 1;
    dp2[nw][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        swap(nw, la);
        memset(dp2[nw], 0, sizeof dp2[nw]);

        if(i == 1 || i == n / 2 + 1) {
            rep(a, 0, n + 1) rep(b, 0, n + 1) rep(c1, 0, 3) rep(c2, 0, 3) {
                dp2[nw][a + (c2 == 1)][b + (c2 == 2)][c2] += dp2[la][a][b][c1] * (c2 == 0 ? 24 : 1);
            }
        } else {
            rep(a, 0, n + 1) rep(b, 0, n + 1) rep(c1, 0, 3) rep(c2, 0, 3) {
                dp2[nw][a + (c2 == 1)][b + (c2 == 2)][c2] += dp2[la][a][b][c1] * ((c2 == 0 ? 24 : 1) - (c2 == c1 ? 1 : 0));
            }
        }
    }
    nw = 0, la = 1;
    dp1[nw][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        swap(nw, la);
        memset(dp1[nw], 0, sizeof dp1[nw]);
        if(i == 1 || i == n / 2 + 1) {
            rep(a, 0, n + 1) rep(c1, 0, 2) rep(c2, 0, 2) {
                        dp1[nw][a + (c2 == 1)][c2] += dp1[la][a][c1] * (c2 == 0 ? 25 : 1);
                    }
        } else {
            rep(a, 0, n + 1) rep(c1, 0, 2) rep(c2, 0, 2) {
                        dp1[nw][a + (c2 == 1)][c2] += dp1[la][a][c1] * ((c2 == 0 ? 25 : 1) - (c2 == c1 ? 1 : 0));
                    }
        }
    }
    nw = 0, la = 1;
    dp0[nw] = 1;
    for (int i = 1; i <= n; i++) {
        swap(nw, la);
        dp0[nw] = 0;
        if(i == 1 || i == n / 2 + 1) {
            dp0[nw] = dp0[la] * 26;
        } else {
            dp0[nw] = dp0[la] * 25;
        }
    }
    mi res = dp0[nw];
    vector<mi> ps1(n + 1, 0);
    rep(i, 0, n + 1) {
        rep(c0, 0, 2) ps1[i] += dp1[nw][i][c0];
    }
    for (int i = n - 1; i >= 0; i--) ps1[i] += ps1[i + 1];

    vector<vector<mi>> ps2(n + 1, vector<mi>(n + 1, 0));
    rep(i, 0, n + 1) {
        rep(j, 0, n + 1) {
            rep(c0, 0, 3) ps2[i][j] += dp2[nw][i][j][c0];
        }
    }
    for (int i = n; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            ps2[i][j] += (i + 1 <= n ? ps2[i + 1][j] : 0) + (j + 1 <= n ? ps2[i][j + 1] : 0)
                    - (i + 1 <= n && j + 1 <= n ? ps2[i + 1][j + 1] : 0);
        }
    }

    rep(i, 0, 26) {
        if(c[i] + 1 <= n) res -= ps1[c[i] + 1];
    }
    rep(i, 0, 26) {
        rep(j, i + 1, 26) {
            if(c[i] + 1 <= n && c[j] + 1 <= n) res += ps2[c[i] + 1][c[j] + 1];
        }
    }
    cout << int(res) << '\n';

}