#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
vi G[N];
vector<mi> dp[N];

vector<mi> merge(vector<mi> A, vector<mi> B) {
    vector<mi> res(k + 1, 0);
    for (int d = 0; d <= k / 2; d++) res[d] = A[d] * B[d];
    for (int d = k / 2 + 1; d <= k; d++) {
        res[d] = (A[d] - A[d - 1]) * B[k - d] + (B[d] - B[d - 1]) * A[k - d] + res[d - 1];
    }
    return res;
}


void dfs(int v, int p) {
    dp[v] = vector<mi>(k + 1, 1);
    for (int nxt : G[v]) {
        if (nxt == p) continue;
        dfs(nxt, v);

        mi dpk = dp[nxt].back();
        dp[nxt].pop_back();
        dp[nxt].insert(dp[nxt].begin(), 0);

        for (auto &x : dp[nxt]) x += dpk;

//        cout << " " << nxt + 1 << ": ";
//        for (mi x : dp[nxt]) cout << int(x) << " ";
//        cout << endl;
        dp[v] = merge(dp[v], dp[nxt]);
    }
//    cout << "out: " << v + 1 << ": ";
//    for (mi x : dp[v]) cout << int(x) << " ";
//    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    cout << int(dp[0][k]) << '\n';


}