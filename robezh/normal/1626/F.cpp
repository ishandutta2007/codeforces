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
const int INF = (int)1e9;

const int N = (int)1e5 + 50;
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

const int M = 2e7;

int n;
int a0;
int x, y, k, md;
mi cnt[M], sum[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> a0 >> x >> y >> k >> md;

    ll G = 1;
    rep(i, 1, k + 1) {
        G = G * i / __gcd((ll)i, G);
    }
//    cout << G << endl;

    ll ca = a0;
    cnt[ca % G] += 1;
    sum[ca % G] += ca;
//    cout << ca << " ";
    rep(i, 1, n) {
        ca = (ca * x + y) % md;
        cnt[ca % G] += 1;
        sum[ca % G] += ca;
//        cout << ca << " ";
    }
//    cout << endl;

    mi res = 0;
    rep(i, 1, k + 1) {
        res *= n;
        for (int j = 0; j < G; j += i) {
            mi sc = 0, ssum = 0;
            rep(l, j, j + i) {
                sc += cnt[l], ssum += sum[l] - (l - j) * cnt[l];
                res += sum[l];
                cnt[l] *= (n - 1);
                sum[l] *= (n - 1);
            }
            cnt[j] += sc;
            sum[j] += ssum;
        }
    }
    cout << int(res) << '\n';


}