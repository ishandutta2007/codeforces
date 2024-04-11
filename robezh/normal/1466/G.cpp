#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int M = (int)2e6 + 5, N = (int)1e5 + 5, MOD = (int)1e9 + 7;

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

int n, q;
mi res[N];
string s0, t;

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
//vector<T> pows = {{1,1}}, ipows = {{1,1}};
T pows[M], ipows[M];

T pref[M];
T p1[M];


T getsub(T ts[], int l, int r) {
    return ((r >= 0? ts[r] : T{0, 0})
            - (l - 1 >= 0 ? ts[l - 1] : T{0, 0}))
                * ipows[l];
}

struct Query {
    string str;
    int idx;
} qrs[N];

mi pw2[N], ipw2[N];
mi inv2 = inv(mi(2));
mi pcnt[N][26];

mi gcnt(int l, int r, int b) {
    if(l >= r) return 0;
    return (pcnt[r][b] - pcnt[l][b]) * ipw2[n - r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pows[0] = {1, 1};
    ipows[0] = {1, 1};
    for(int i = 1; i < M; i++) pows[i] = pows[i - 1] * base, ipows[i] = ipows[i - 1] * ibase;
    pw2[0] = ipw2[0] = 1;
    rep(i, 1, N) pw2[i] = pw2[i - 1] * 2, ipw2[i] = ipw2[i - 1] * inv2;

    cin >> n >> q;
    cin >> s0 >> t;
    t = " " + t;
    rep(i, 0, q) {
        cin >> qrs[i].idx >> qrs[i].str;
    }
    vi idx(q, 0);
    iota(all(idx), 0);
    sort(all(idx), [](const int i, const int j) {
        return sz(qrs[i].str) < sz(qrs[j].str);
    });

    rep(i, 1, n + 1) {
        rep(b, 0, 26) pcnt[i][b] = (i ? pcnt[i - 1][b] : 0) + ((t[i] - 'a') == b) * pw2[n - i];
    }

    int cur_i = 0;
    bool hashed = false;
    int len;
    for(int id : idx) {
        auto &qr = qrs[id];
        while(sz(s0) < sz(qr.str)) {
            hashed = false;
            cur_i++;
            s0 = s0 + t[cur_i] + s0;
        }
        if(!hashed) {
            len = sz(s0);
            for(int i = 0; i < len; i++)
                pref[i] = (i ? pref[i - 1] : T{0, 0}) + pows[i] * T{s0[i], s0[i]};
            hashed = true;
        }

        if(qr.idx < cur_i) {
            res[id] = 0;
            continue;
        }

        string &str = qrs[id].str;
        int slen = sz(str);
        for(int j = 0; j < slen; j++) {
            p1[j] = (j ? p1[j - 1] : T{0, 0}) + pows[j] * T{str[j], str[j]};
        }

        int ocnt = 0;
        for(int j = 0; j + slen <= len; j++) {
            ocnt += (getsub(pref, j, j + slen - 1) == getsub(p1, 0, slen - 1));
        }
        res[id] = ocnt * pw2[qr.idx - cur_i];

        for(int sp = 0; sp < slen; sp++) {
            int len_p = sp, len_s = slen - sp - 1;
            if(getsub(p1, 0, sp - 1) == getsub(pref, len - len_p, len - 1) &&
               getsub(p1, sp + 1, slen - 1) == getsub(pref, 0, len_s - 1))
                    res[id] += gcnt(cur_i, qrs[id].idx, str[sp] - 'a');
        }
    }

    rep(i, 0, q) cout << int(res[i]) << "\n";

}