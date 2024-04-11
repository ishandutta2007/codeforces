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
const int N = (int)1e5 + 50;
const int mod = (int)1e9 + 7, inv2 = (mod + 1) / 2;
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

int n;
set<int> G[N];
int depth[N], par[N], sub[N];
int lb[N], rb[N], ln[N];
mi iv[N];


int dfs1(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p)
            sub[v] += dfs1(nxt, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(int nxt : G[v]){
        if(nxt != p && sub[nxt] > nn/2) return dfs2(nxt, v, nn);
    }
    return v;
}

struct P {
    int pos;
    mi d0, d1;
};

mi multi = 1;

mi solve_v(int v, int off) {
    vector<P> ps;
    function<void(int, int, int)> solve = [&](int v, int p, int d) {
        ps.push_back({lb[v], iv[ln[v]], mi(d + off) * iv[ln[v]]});
        ps.push_back({rb[v] + 1, -iv[ln[v]], -mi((d + off)) * iv[ln[v]]});
        for (int nxt : G[v]) {
            if(nxt == p) continue;
            solve(nxt, v, d + 1);
        }
    };
    solve(v, -1, 0);
    sort(all(ps), [](const P &p1, const P &p2) {
        return p1.pos < p2.pos;
    });
    int r = 0;
    mi res = 0;
    mi c0 = 0, c1 = 0;
    for (int i = 0; i < sz(ps); i = r) {
        while(r < sz(ps) && ps[i].pos == ps[r].pos) r++;
        if(r < sz(ps)) {
            rep(j, i, r) {
                c0 += ps[j].d0;
                c1 += ps[j].d1;
            }
            int nxtpos = ps[r].pos;
//            cout << nxtpos << " " << ps[i].pos << " " << int(c0 * c1 * multi * 2) << endl;
            res += (nxtpos - ps[i].pos) * c0 * c1 * 2;
        }
    }
    return res;

}

mi totres = 0;

void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    par[centroid] = p;

    mi res = solve_v(centroid, 0);
//    cout << "solving centroid " << centroid << ": " << int(res * multi) << endl;
    for(int nxt : G[centroid]){
        G[nxt].erase(centroid);
        mi pres = solve_v(nxt, 1);
//        cout << centroid << " to " << nxt << ": " << int(pres * multi) << endl;
        res -= pres;
    }
    for(int nxt : G[centroid]) {
        decompose(nxt, centroid);
    }
    G[centroid].clear();
    res /= 2;
    totres = (totres + res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, N) iv[i] = inv(mi(i));
    rep(i, 0, n) {
        cin >> lb[i] >> rb[i];
        ln[i] = rb[i] - lb[i] + 1;
        multi *= ln[i];
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    decompose(0, -1);
    cout << int(totres * multi) << endl;

}