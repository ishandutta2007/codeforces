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


const int N = (int)2e5 + 50;

int n;
int p[N];
int cnt[N], mx[N];

struct edge {
    int to, x, y;
};
vector<edge> G[N];


void dfs(int v, int par) {

    for (auto &e : G[v]) {
        if(e.to == par) continue;
        vector<pii> upd;
        int c = e.y;
        while(c > 1) {
            upd.emplace_back(p[c], cnt[p[c]]);
            cnt[p[c]]--;
            c /= p[c];
        }
        c = e.x;
        while(c > 1) {
            upd.emplace_back(p[c], cnt[p[c]]);
            cnt[p[c]]++;
            mx[p[c]] = max(mx[p[c]], cnt[p[c]]);
            c /= p[c];
        }
        dfs(e.to, v);
        reverse(all(upd));
        for(auto &pr : upd) {
            cnt[pr.first] = pr.second;
        }
    }
}

mi res = 0;

void solve(int v, int par, mi cur) {
    res += cur;
    for (auto &e : G[v]) {
        if(e.to == par) continue;
        solve(e.to, v, cur / e.x * e.y);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    iota(p, p + N, 0);
    rep(i, 2, N) {
        if(p[i] != i) continue;
        for (int j = 2 * i; j < N; j += i) p[j] = i;
    }

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) G[i].clear();
        fill(cnt, cnt + n + 1, 0);
        fill(mx, mx + n + 1, 0);
        rep(i, 0, n - 1) {
            int u, v, x, y; cin >> u >> v >> x >> y; u--, v--;
            int g = __gcd(x, y);
            x /= g, y /= g;
            G[u].push_back({v, x, y});
            G[v].push_back({u, y, x});
        }
        dfs(0, -1);
        res = 0;
        mi r1 = 1;
        rep(i, 2, n + 1) {
//            cout << i << " " << mx[i] << endl;
            r1 *= pow(mi(i), mx[i]);
        }
        solve(0, -1, r1);
        cout << int(res) << '\n';
    }


}