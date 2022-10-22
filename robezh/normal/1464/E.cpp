#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
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
const int N = (1 << 17);

int n, m;
int dp[N];
vi G[N];

int getnim(int v) {
    if(dp[v] != -1) return dp[v];
    vi res;
    for(int nxt : G[v]) res.push_back(getnim(nxt));
    sort(all(res));
    res.resize(unique(all(res)) - res.begin());
    rep(i, 0, sz(res)) {
        if(res[i] != i) return dp[v] = i;
    }
    return dp[v] = sz(res);
}

mi inv2 = inv(mi(2));

void FWTxor(mi *a, int opt) {
    for(int mid = 1; mid < N; mid <<= 1)
        for(int R = mid << 1, j = 0; j < N; j += R)
            for(int k = 0; k < mid; k++) {
                mi x = a[j + k], y = a[j + k + mid];
                if(opt == 1) a[j + k] = x + y,  a[j + k + mid] = x - y;
                else a[j + k] = (x + y) * inv2, a[j + k + mid] = (x - y) * inv2;
            }
}

mi freq[N + 5];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
    }
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n) freq[getnim(i)] += 1;
    mi invn1 = inv(mi(n + 1));
    FWTxor(freq, 1);
    rep(i, 0, N) {
        freq[i] *= invn1;
        freq[i] = freq[i] / (1 - freq[i]);
    }
    FWTxor(freq, -1);
    cout << int(1 - invn1 * (1 + freq[0])) << '\n';



}