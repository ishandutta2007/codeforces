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

const int M = (int)1e7 + 50, N = (int)5e5 + 50;

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


int n, a[N];
int p[M];
int cnt[M], rcnt[M];
mi s[M];
int bct[N];
int mu[M];
mi s1;
int mm[N];
mi pw[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mm[0] = -1;
    rep(i, 1, N) {
        mm[i] = ((i & (i - 1)) == 0 ? 1 : 0) + mm[i - 1];
        bct[i] = bct[i / 2] + (i & 1);
    }
    pw[0] = 1;
    rep(i, 1, N) pw[i] = pw[i - 1] * 2;

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
        rcnt[a[i]]++;
    }

    iota(p, p + M, 0);
    fill(mu, mu + M, 1);
    for (int i = 2; i < M; i++) {
        if(p[i] == i) {
            for (int j = i; j < M; j += i) {
                p[j] = i;
                mu[j] = -mu[j];
            }
            for (ll j = 1LL * i * i; j < M; j += 1LL * i * i) mu[j] = 0;
        }
    }

    for (int i = 1; i < M; i++) {
        for (int j = 2 * i; j < M; j += i) cnt[i] += cnt[j];
    }
    rep(i, 1, M) {
        s[i] = pw[cnt[i]] - 1;
    }

    mi res = 0;
    vi pm;
    vi pd;
    rep(i, 0, M) {
        if(rcnt[i]) {
            pm.clear();
            int v = i;
            while(v > 1) {
                int cp = p[v];
                pm.push_back(cp);
                while(v % cp == 0) v /= cp;
            }
            pd.clear();
            pd.resize(1 << sz(pm), 1);
            rep(mask, 1, 1 << sz(pm)) {
                int b = mm[mask];
                pd[mask] = pd[mask ^ (1 << b)] * pm[b];
            }

            mi cres = 0;
            rep(mask, 0, 1 << sz(pm)) {
                int sg = bct[mask] % 2 == 0 ? 1 : -1;
//                cout << i << " " << pd[mask] << " " << (int)s[pd[mask]] << endl;
                cres += sg * s[pd[mask]];
            }
            res += rcnt[i] * cres;
        }
    }

    rep(i, 1, M) s1 += s[i] * mu[i];
    res -= n * s1;
    cout << int(res) << '\n';

}