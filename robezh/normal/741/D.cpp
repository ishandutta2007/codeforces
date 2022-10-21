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

const int N = (int)5e5 + 50, B = 22, M = (1 << 22), INF = (int)1e9;

struct edge {
    int to;
    char c;
};

int n;
int bag[M];
vi in;
int sz[N], val[N];
vector<edge> G[N];
int dep[N];
int dp[N];
unordered_map<int, int> mp[N];

struct Bag {
    void add(int x, int val) {
        if(bag[x] == -INF) in.push_back(x);
        bag[x] = max(bag[x], val);
    }
    void clear() {
        for (int x : in) bag[x] = -INF;
        in.clear();
    }
} bg;

void dfs_sz(int v, int d, int curval) {
    sz[v] = 1;
    dep[v] = d;
    val[v] = curval;

    for(auto &e: G[v]) {
        dfs_sz(e.to, d + 1, curval ^ (1 << (e.c - 'a')));
        sz[v] += sz[e.to];
        if(sz[e.to] > sz[G[v][0].to]) {
            swap(e, G[v][0]);
        }
    }
}

void add_to_bag(int v, int getson) {
    bg.add(val[v], dep[v]);
    if(getson) {
        for (auto &e : G[v]) add_to_bag(e.to, getson);
    }
}

int get_max(int v, int getson, int ca) {
    int res = dep[v] + bag[val[v]] - 2 * dep[ca];
    rep(i, 0, B) {
        res = max(res, dep[v] + bag[val[v] ^ (1 << i)] - 2 * dep[ca]);
    }
    if(getson) {
        for (auto &e : G[v]) res = max(res, get_max(e.to, getson, ca));
    }
    return res;
}

void solve(int v) {
    if(sz(G[v])) {
        rep(i, 1, sz(G[v])) {
            solve(G[v][i].to);
            dp[v] = max(dp[v], dp[G[v][i].to]);
            bg.clear();
        }
        solve(G[v][0].to);
        dp[v] = max(dp[v], dp[G[v][0].to]);
    }
    dp[v] = max(dp[v], get_max(v, 0, v));
    add_to_bag(v, 0);
    rep(i, 1, sz(G[v])) {
        dp[v] = max(dp[v], get_max(G[v][i].to, 1, v));
        add_to_bag(G[v][i].to, 1);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    fill(bag, bag + M, -INF);
    rep(i, 1, n) {
        int p;
        char c;
        cin >> p >> c; p--;
        G[p].push_back({i, c});
    }
    dfs_sz(0, 0, 0);
    solve(0);
    rep(i, 0, n) cout << dp[i] << " ";
    cout << endl;
}