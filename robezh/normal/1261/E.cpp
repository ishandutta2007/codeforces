#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 1005;

int n;
pii p[N];
int a[N];
int ans[N][N];
const int MOD = (int)1e9 + 9;

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


mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef array<int,2> T; // bases not too close to ends
uniform_int_distribution<int> BDIST(0.1*MOD,0.9*MOD);
const T base = {BDIST(rng),BDIST(rng)};
//const T base = {10, 10};
const T ibase = {(int)inv(mi(base[0])),(int)inv(mi(base[1]))};
T operator+(T l, T r) {
    rep(i,0,2) if ((l[i] += r[i]) >= MOD) l[i] -= MOD;
    return l; }
T operator-(T l, T r) {
    rep(i,0,2) if ((l[i] -= r[i]) < 0) l[i] += MOD;
    return l; }
T operator*(T l, T r) {
    rep(i,0,2) l[i] = (ll)l[i]*r[i]%MOD;
    return l; }
vector<T> pows = {{1,1}}, ipows = {{1,1}};

T psum[N][N];

void create(int i, int j, int x) {
    ans[i][j] = x;
    psum[i][j] = T{1 + x, 1 + x} * pows[j];
    if(j) psum[i][j] = psum[i][j - 1] + psum[i][j];
    a[j] -= x;
}

void solve(int m) {
    if(m == 1) {
        assert(a[0] == 1);
        create(0, 0, 0);
        create(1, 0, 1);
        return ;
    }

    for (int i = 0; i < m - 1; i++) {
        create(m, i, a[i] > 1);
    }
    solve(m - 1);

    create(m, m - 1, 1);
    int pos = -1;

    for (int i = 0; i < m; i++) {
        if(psum[i][m - 2] == psum[m][m - 2]) pos = i;
    }
    for (int i = 0; i < m; i++) {
        create(i, m - 1, a[m - 1] && i != pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (sz(pows) < N) pows.push_back(base*pows.back()), ipows.push_back(ibase*ipows.back());

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
//        cin >> p[i].first;
//        p[i].second = i;
    }
//    sort(p, p + n);
//    rep(i, 0, n) a[i] = p[i].first;
    solve(n);
    cout << n + 1 << '\n';
    rep(i, 0, n + 1) {
        rep(j, 0, n) cout << ans[i][j];
        cout << '\n';
    }

}