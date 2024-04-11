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
const int N = 405, INF = (int)1e9;

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

int n, m;
int dis[N][N], pv[N][N];
int sev[N][N];
vi G[N];

void bfs(int s) {
    int *dist = dis[s];
    dist[s] = 0;
    pv[s][s] = -1;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        auto v = que.front(); que.pop();
        for (int nxt : G[v]) {
            if(dist[nxt] == INF) {
                dist[nxt] = dist[v] + 1;
                pv[s][nxt] = v;
                que.push(nxt);
            } else if(dist[nxt] == dist[v] + 1) {
                sev[s][nxt] = 1;
            }
        }
    }
}

mi solve(int s, int t) {
    int d = dis[s][t];
    if(sev[s][t]) return 0;
    mi res = 1;
    vi vs(d + 1);
    int cur = s;
    rep(i, 0, d + 1) vs[i] = cur, cur = pv[t][cur];
    rep(i, 0, n) {
        if(i == s || i == t) continue;
        if(((dis[s][i] + dis[i][t]) - d) % 2 != 0) return 0;
        int br = ((dis[s][i] + dis[i][t]) - d) / 2;
        int loc = dis[s][i] - br;
        if(dis[vs[loc]][i] != br) return 0;

        if(br) {
            mi cnt = 0;
            for (int nxt : G[i]) {
                if(dis[vs[loc]][i] == dis[vs[loc]][nxt] + 1) cnt += 1;
            }
            res *= cnt;
        }
    }
    return res;
}

mi res[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, N) {
        fill(dis[i], dis[i] + N, INF);
    }
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 0, n) {
        bfs(i);
//        rep(j ,0, n) cout << dis[i][j] << " ";
//        cout << endl;
    }


    rep(i, 0, n) {
        rep(j, i, n) res[i][j] = solve(i, j);
    }
    rep(i, 0, n) rep(j, 0, i) res[i][j] = res[j][i];
    rep(i, 0, n) {
        rep(j, 0, n) cout << int(res[i][j]) << " ";
        cout << '\n';
    }
}