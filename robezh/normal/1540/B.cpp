#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
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

const int N = 205;

int n ;
double sdp[N][N], scmu[N][N];
mi dp[N][N], cmu[N][N];
int dep[N], par[N];
int tin[N], tout[N], tim;
mi inv2 = inv(mi(2));

vi G[N];

void dfs(int v, int p, int d) {
    tin[v] = tim++;
    dep[v] = d;
    par[v] = p;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v, d + 1);
    }
    tout[v] = tim - 1;
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    while(dep[v] > dep[u]) v = par[v];
    while(u != v) u = par[u], v = par[v];
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    dp[0][0] = 1;
    sdp[0][0] = 1;
    rep(i, 0, n) {
        rep(j, 0, n) {
            dp[i + 1][j] += inv2 * dp[i][j];
//            sdp[i + 1][j] += 0.5 * sdp[i][j];
            dp[i][j + 1] += inv2 * dp[i][j];
//            sdp[i][j + 1] += 0.5 * sdp[i][j];
            cmu[i + 1][j + 1] += inv2 * dp[i][j];
//            scmu[i + 1][j + 1] += 0.5 * sdp[i][j];
        }
    }
    rep(i, 1, n) {
        cmu[i][0] = 1;
        scmu[i][0] = 1;
        rep(j, 1, n) {
            cmu[i][j] += cmu[i - 1][j];
//            scmu[i][j] += scmu[i - 1][j];
//            cout << i << " " << j << " " << scmu[i][j] << endl;
        }
    }

    rep(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    mi res = 0;
    rep(i, 0, n) {
        dfs(i, -1, 0);
        mi coe = mi(1) / n;
        rep(u, 0, n) {
            rep(v, 0, u) {
                int ca = lca(u, v);
                res += coe * cmu[dep[v] - dep[ca]][dep[u] - dep[ca]];
            }
        }
    }
    cout << int(res) << endl;


}