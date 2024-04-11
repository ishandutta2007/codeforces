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

const int N = (int)2e5 + 50, K = 2005;

mi fac[N], facinv[N];

mi C(ll n, ll k) {
    if(n < 0 || k < 0 || n - k < 0) return 0;
    return fac[n] * facinv[k] * facinv[n - k];
}

int n, m, k, s;
vector<pii> vs;
mi dp[K][23];
mi ipw[N], pw[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);
    assert(int(C(5, 2)) == 10);

    mi iv2 = inv(mi(2));
    ipw[0] = pw[0] = 1;
    rep(i, 1, N) pw[i] = pw[i - 1] * 2, ipw[i] = ipw[i - 1] * iv2;

    cin >> n >> m >> k >> s;

    if(n == 1 && m == 1) {
        if(k == 0) cout << s << endl;
        else cout << (s + 1) / 2 << endl;
        return 0;
    }

    vs.push_back({1, 1});
    vs.push_back({n, m});
    s *= 4;
    rep(i, 0, k) {
        int x, y; cin >> x >> y;
        vs.push_back({x, y});
        if((x == 1 && y == 1) || (x == n && y == m)) s /= 2;
    }
    sort(all(vs), [](const pii &p1, const pii &p2) {
        return p1.first + p1.second < p2.first + p2.second;
    });
    vs.resize(unique(all(vs)) - vs.begin());
    k = sz(vs);
    dp[k - 1][1] = 1;
    for (int i = k - 2; i >= 0; i--) {
        for (int lg = 2; lg <= 22; lg++) {
            for (int j = i + 1; j < k; j++) {
                int dx = vs[j].first - vs[i].first, dy = vs[j].second - vs[i].second;
                if(dx >= 0 && dy >= 0) {
                    dp[i][lg] += dp[j][lg - 1] * C(dx + dy, dx);
                }
            }
        }
        for (int lg = 2; lg < 22; lg++) {
            dp[i][lg] -= dp[i][lg + 1];
        }
    }
    mi res = 0;
    int cs = s;
    rep(lg, 1, 23) {
        cs = (cs + 1) / 2;
        res += dp[0][lg] * cs;
    }
    cout << int(res * inv(C(n + m - 2, n - 1))) << endl;


}