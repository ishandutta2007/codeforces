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
const int N = 105;

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


typedef vector<mi> poly;
typedef vector<poly> poly2;

int n;
poly2 dp[N];
mi fac[N], facinv[N];
vi G[N];
int sub[N];

mi C(int n, int k) {
    return fac[n] * facinv[n - k] * facinv[k];
}

poly2 poly2_mul(poly2 &a, poly2 &b) {
    poly2 res(sz(a) + sz(b) - 1, poly(sz(a[0]) + sz(b[0]) - 1, 0));
    rep(i, 0, sz(a)) {
        rep(j, 0, sz(b)) {
            rep(i2, 0, sz(a[0])) {
                rep(j2, 0, sz(b[0])) {
                    res[i + j][i2 + j2] += a[i][i2] * b[j][j2];
                }
            }
        }
    }
    return res;
}

void dfs(int v, int p) {
    sub[v] = 1;
    dp[v] = {{0, 1}};

    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        sub[v] += sub[nxt];
        dp[v] = poly2_mul(dp[v], dp[nxt]);
    }
    dp[v].push_back(poly(sub[v] + 1, 0));
    for (int i = sz(dp[v]) - 1; i >= 1; i--) {
        mi add = 0;
        rep(j, 0, sz(dp[v][i - 1])) {
            add += j * dp[v][i - 1][j];
        }
        dp[v][i][0] += add;
    }
}

mi invn = 0;

mi gpower(int k) {
    if(k >= 0) return pow(mi(n), k);
    else if(k == -1) return invn;
    assert(false);
}

mi res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);

    cin >> n;

    invn = inv(mi(n));

    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = n - 1; i >= 0; i--) {
        res[i] = dp[0][n - i][0] * gpower(n - i - 2);
        rep(j, i + 1, n) res[i] -= C(j, i) * res[j];
    }
    rep(i, 0, n) {
        cout << int(res[i]) << " ";
    }
    cout << '\n';
}