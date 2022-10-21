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

const int N = (int)3e5 + 50;

mi fac[N], facinv[N];

mi C(ll n, ll k) {
    if(n < 0 || k < 0 || n - k < 0) return 0;
    return fac[n] * facinv[k] * facinv[n - k];
}


int gp[N];
vi G[N];
int c = 0;
vi vs[N];
vi gdp[N];
int in[N];
int g[40][40];
vector<mi> ways = {1};
int cnt;

int dfs(int v, int c) {
    gp[v] = c;
    int res = 1;
    for (int nxt : G[v]) {
        if(!gp[nxt]) res += dfs(nxt, c);
    }
    return res;
}

int n, m;
map<pii, int> con;
vector<int> add[N], del[N];


vector<mi> mul(vector<mi> a, vector<mi> b) {
    vector<mi> res(sz(a) + sz(b) - 1, 0);
    rep(i, 0, sz(a)) {
        rep(j, 0, sz(b)) res[i + j] += a[i] * b[j];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fac[0] = 1;
    rep(i, 1, N) fac[i] = fac[i - 1] * i;
    facinv[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i--) facinv[i] = facinv[i + 1] * (i + 1);


    cin >> n >> m;
    rep(i, 0, n) {
        int l, r; cin >> l >> r;
        add[l].push_back(i);
        del[r + 1].push_back(i);
    }
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        con[{u, v}] = con[{v, u}] = 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 0, n) {
        if(!gp[i]) {
            if(dfs(i, c + 1) == 1) gp[i] = 0;
            else c++;
        }
    }
    rep(i, 0, n) if(gp[i]) vs[gp[i]].push_back(i);

//    cout << c << endl;
//    rep(i, 1, c + 1) {
//        cout << i << ": ";
//        for (int x : vs[i]) cout << x << " ";
//        cout << endl;
//    }
    rep(i, 1, c + 1) {
        rep(j, 0, sz(vs[i])) fill(g[j], g[j] + sz(vs[i]), 0);
        rep(j, 0, sz(vs[i])) {
            rep(k, 0, sz(vs[i])) g[j][k] = con[{vs[i][j], vs[i][k]}];
        }
        vi &dp = gdp[i];

        dp = vi(1 << sz(vs[i]), 0);
        dp[0] = 1;
        rep(mask, 0, 1 << sz(vs[i])) {
            rep(j, 0, sz(vs[i])) {
                if(mask >> j & 1) continue;
                bool good = true;
                rep(k, 0, sz(vs[i])) good &= !(mask >> k & 1) || !g[j][k];
                dp[mask ^ (1 << j)] |= good && dp[mask];
            }
        }
    }

    mi res = 0;

    rep(i, 1, n + 1) {
        int rb = 0;
        for (int x : add[i]) {
            if(!gp[x]) cnt++;
            else rb = 1;
            in[x] = 1;
        }
        for (int x : del[i]) {
            if(!gp[x]) cnt--;
            else rb = 1;
            in[x] = 0;
        }
        if(rb) {
            ways = {1};
            rep(j, 1, c + 1) {
                int mask = 0;
                rep(ti, 0, sz(vs[j])) mask |= (in[vs[j][ti]] << ti);
                vector<mi> cc(sz(vs[j]) + 1, 0);
                for(int sub = mask; ; sub = (sub - 1) & mask) {
                    cc[__builtin_popcount(sub)] += gdp[j][sub];
                    if(sub == 0) break;
                }
                ways = mul(ways, cc);
            }
        }


//        cout << i << ", cnt: " << cnt << ", ways: ";
//        rep(j, 0, sz(ways)) cout << int(ways[j]) << " ";
//        cout << endl;

        rep(j, 0, sz(ways)) {
            res += ways[j] * C(cnt, i - j);
        }

//        cout << int(res) << endl;
    }
    cout << int(res) << '\n';
}