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

const int N = (int)1e6 + 50;

int n, p;

mi solve() {
    cin >> n >> p;

    vi xs(n);
    for(int i = 0; i < n; i++) cin >> xs[i];
    if(p == 1) {
        return mi(n % 2);
    }
    sort(all(xs), [](int a, int b) {
        return a > b;
    });

    ll d = 0;
    mi res;
    int r = 0;
    int la = -1;
    for(int i = 0; i < n; i = r) {
        while(r < n && xs[r] == xs[i]) r++;
        if(la != -1 && d != 0) {
            for(int j = 0; j < la - xs[i]; j++) {
                d *= p;
                if(d >= n + 1) {
                    for(int u = i; u < sz(xs); u++) {
                        res -= pow(mi(p), xs[u]);
                    }
                    return res;
                }
            }
        }
        la = xs[i];

        for(int j = i; j < r; j++) {
            if(d == 0) {
                res += pow(mi(p), xs[i]);
                d++;
            }
            else {
                res -= pow(mi(p), xs[i]);
                d--;
            }
        }

    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (int)solve() << '\n';
    }

}