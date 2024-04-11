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

const int N = (int)1e5 + 50, LOGN = 18;



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

struct edge {
    int to, cost;
};

vector<edge> G[N];
int n;
int parent[LOGN][N];
int depth[N];
ll dis[N];

int tin[N], tout[N], tim;
void dfs(int v, int p, int d, ll d2){
    parent[0][v] = p;
    depth[v] = d;
    dis[v] = d2;
    tin[v] = tim++;
    for(auto &e : G[v]){
        if(e.to != p) dfs(e.to, v, d+1, d2 + e.cost);
    }
    tout[v] = tim - 1;
}

void init(){
    dfs(0, -1, 0, 0);

    for(int k = 0; k+1 < LOGN; k++){
        for(int v = 0; v < n; v++){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]){int tmp = u; u = v; v = tmp;}
    for(int k = 0; k < LOGN; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = LOGN - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}


ll get_dis(int u, int v) {
    int ca = lca(u, v);
    return dis[u] + dis[v] - 2 * dis[ca];
}


mi dp[N][3];
vector<pii> qr[N];

void add(int v, int to, int ec, int d) {
    dp[v][0] += d * (dp[to][0]);
    dp[v][1] += d * (dp[to][0] * ec + dp[to][1]);
    dp[v][2] += d * (dp[to][0] * ec * ec + dp[to][1] * 2 * ec + dp[to][2]);
}

void dfs(int v, int p) {
    dp[v][0] = 1;
    dp[v][1] = dp[v][2] = 0;
    for (auto &e : G[v]) {
        if(e.to == p) continue;
        dfs(e.to, v);
        add(v, e.to, e.cost, 1);
    }
}

mi res[N];

void reroot(int v, int p, int pcost) {
    if(p != -1) {
        add(v, p, pcost, 1);
    }


    for (auto &pr : qr[v]) {
        int u, idx;
        tie(u, idx) = pr;

        if(tin[u] <= tin[v] && tin[v] <= tout[u]) {
            res[idx] = dp[v][2];
            int to = parent[0][u];
            if(to != -1) {
                mi len = mi(get_dis(v, to));
                res[idx] -= 2 * (dp[to][0] * len * len + dp[to][1] * 2 * len + dp[to][2]);
            }
        } else {
            int to = u;
            mi len = mi(get_dis(v, to));

            res[idx] = 2 * (dp[to][0] * len * len + dp[to][1] * 2 * len + dp[to][2]);
            res[idx] -= dp[v][2];
        }
//        cout << "all: " << int(bt) << endl;

    }

    for (auto &e : G[v]) {
        if(e.to == p) continue;
        add(v, e.to, e.cost, -1);
        reroot(e.to, v, e.cost);
        add(v, e.to, e.cost, 1);
    }

    if(p != -1) {
        add(v, p, pcost, -1);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v, cost; cin >> u >> v >> cost; u--, v--;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }
    init();
    int q;
    cin >> q;
    rep(i, 0, q) {
        int u, v; cin >> u >> v; u--, v--;
        qr[u].push_back({v, i});
    }
    dfs(0, -1);
     reroot(0, -1, 0);
    rep(i, 0, q) {
        cout << int(res[i]) << '\n';
    }


}