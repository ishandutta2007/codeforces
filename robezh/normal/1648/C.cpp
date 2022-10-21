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
const int N = (int)2e5 + 50;



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


mi bit[N];

void add(int x, int val) {
    for(int i = x; i < N; i |= i + 1) bit[i] += val;
}

mi get(int x) {
    mi res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

mi fac[N], facinv[N];
int n, m;
int s[N], t[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);


    assert(fac[10] * facinv[10] == 1);

    cin >> m >> n;
    rep(i, 0, m) {
        cin >> t[i];
        add(t[i], 1);
        cnt[t[i]]++;
    }

    mi S = 1;

    rep(i, 0, n) {
        cin >> s[i];

    }
    rep(i, 0, N) S *= facinv[cnt[i]];
    S *= fac[m];

    mi res = 0;
    int tot = m;
    rep(i, -1, n - 1) {
        if(i != -1) {
            if(cnt[s[i]] == 0) break;
            S /= tot--;
            S *= cnt[s[i]]--;
            add(s[i], -1);
        }

        if(tot == 0) {
            res += 1;
        } else {
            res += S / mi(tot) * get(s[i + 1] - 1);
//            cout << i << " " << int(S) << " " << int(get(s[i + 1] - 1)) << " " << int(S * inv(mi(tot)) * get(s[i + 1] - 1)) << endl;
        }
    }
    cout << int(res) << endl;

}