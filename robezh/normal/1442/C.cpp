#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2e5 + 50;
const int INF = (int)1e9;

const int MOD = (int)998244353;

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
    int to, c;
};

int n, m;
pii dis[N][2];
vector<edge> G[N];
int dist[N][20][2];

struct state {
    int v, k, c;
};

typedef pair<pii, pii> ppii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, 1});
        G[b].push_back({a, 0});
    }
    rep(i, 0, n) {
        rep(j, 0, 2) dis[i][j] = {INF, INF};
    }
    dis[0][1] = {0, 0};
    priority_queue<ppii, vector<ppii>, greater<> > pque;
    pque.push({{0, 0}, {0, 1}});
    while(!pque.empty()) {
        auto p = pque.top(); pque.pop();
        int a, b, c0, c1;
        tie(c0, c1) = p.first;
        tie(a, b) = p.second;
        if(pii{c0, c1} > dis[a][b]) continue;
        for(auto &e : G[a]) {
            pii nxtcost = {c0 + (e.c != b), c1 + 1};
            if(nxtcost < dis[e.to][e.c]) {
                dis[e.to][e.c] = nxtcost;
                pque.push({nxtcost, {e.to, e.c}});
            }
        }
    }
    if(min(dis[n - 1][0], dis[n - 1][1]).first >= 20) {
//        cout << min(dis[n - 1][0], dis[n - 1][1]).first << " " << min(dis[n - 1][0], dis[n - 1][1]).second << endl;
        pii p = min(dis[n - 1][0], dis[n - 1][1]);
        cout << int(pow(mi(2), p.first) - 1 + p.second) << '\n';
    } else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 20; j++) {
                dist[i][j][0] = dist[i][j][1] = INF;
            }
        }
        dist[0][0][1] = 0;
        queue<state> que;
        que.push({0, 0, 1});
        while(!que.empty()) {
            auto st = que.front(); que.pop();
            int v = st.v, k = st.k, c = st.c;
            for(auto e : G[v]) {
                int nxtcost = dist[v][k][c] + 1;
                int nv = e.to, nk = k + (e.c != st.c), nc = e.c;
                if(nk < 20 && dist[nv][nk][nc] == INF) {
                    dist[nv][nk][nc] = nxtcost;
                    que.push({nv, nk, nc});
                }
            }
        }
        int res = INF;
        for(int j = 0; j < 20; j++) {
            for(int k = 0; k < 2; k++) {
                if(dist[n - 1][j][k] == INF) continue;
                res = min(res, int(pow(mi(2), j) - 1 + dist[n - 1][j][k]));
            }
        }
        cout << res << '\n';
    }


}