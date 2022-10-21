#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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

const int M = (int)1e6 + 50;

int n, m, k;
int cntr[M][2], cntc[M][2], cnt[2];
map<pii, int> mp;
mi inv2;
mi pw[M];
int br, bc;
mi sr, sc, s;


void add(int x, int y, int c) {
    cnt[(x + y + c) % 2]++;

    br -= cntr[x][0] && cntr[x][1];
    if(cntr[x][0] == 0 && cntr[x][1] == 0) sr *= inv2;
    cntr[x][(y + c) % 2]++;
    br += cntr[x][0] && cntr[x][1];

    bc -= cntc[y][0] && cntc[y][1];
    if(cntc[y][0] == 0 && cntc[y][1] == 0) sc *= inv2;
    cntc[y][(x + c) % 2]++;
    bc += cntc[y][0] && cntc[y][1];
}

void del(int x, int y, int c) {
    cnt[(x + y + c) % 2]--;

    br -= cntr[x][0] && cntr[x][1];
    cntr[x][(y + c) % 2]--;
    if(cntr[x][0] == 0 && cntr[x][1] == 0) sr *= 2;
    br += cntr[x][0] && cntr[x][1];

    bc -= cntc[y][0] && cntc[y][1];
    cntc[y][(x + c) % 2]--;
    if(cntc[y][0] == 0 && cntc[y][1] == 0) sc *= 2;
    bc += cntc[y][0] && cntc[y][1];

}

mi calc() {
    mi res = (bc ? 0 : sc) + (br ? 0 : sr);
//    cout << int(sc) << " " << int(sr) << " " << (cnt[0] && cnt[1] ? 0 : (cnt[0] || cnt[1] ? 1 : 2)) << endl;
    res -= (cnt[0] && cnt[1] ? 0 : (cnt[0] || cnt[1] ? 1 : 2));
//    cout << bc << " " << br << endl;
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw[0] = 1;
    rep(i, 1, M) pw[i] = pw[i - 1] * 2;
    inv2 = inv(mi(2));

    cin >> n >> m >> k;
    sr = pw[n];
    sc = pw[m];
    br = bc = 0;

    rep(i, 0, k) {
        int x, y, t;
        cin >> x >> y >> t;
        if(!mp.count({x, y})) mp[{x, y}] = -1;
        int &val = mp[{x, y}];
        if(val != -1) {
            del(x, y, val);
        }
        if(t >= 0) {
            add(x, y, t);
        }
        val = t;
        cout << int(calc()) << '\n';
    }



}