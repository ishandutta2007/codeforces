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

const int N = (int)2e5 + 50, K = 600, B = (N + K - 1) / K;
const int INF = (int)1e9;

struct Qr {
    int k, idx;
};

int n, q;
vi G[N];
int dp[N];
vector<Qr> qr[N];
int res[N];
int tmp[B];
int ord[N], tim, par[N];
vector<pii> q2[N];
vector<pii> es;

void dfs(int v, int p) {
    ord[tim++] = v;
    par[v] = p;
    for (int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v);
            es.push_back({v, nxt});
        }
    }
}

void calc(int k) {
    fill(dp, dp + n, 0);
    for(auto &e : es) {
        dp[e.first] += max(1, dp[e.second] - k);
    }
    for (auto &p : q2[k]) {
        res[p.second] = dp[p.first];
    }
}

int sub[N], mx[N][B + 1];

void solve(int v, int p) {
    sub[v] = 1;
    fill(mx[v], mx[v] + B + 1, -INF);
    mx[v][0] = 0;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        solve(nxt, v);
        copy(mx[v], mx[v] + min(sub[v] + sub[nxt], B) + 1, tmp);
        for (int i = 0; i <= sub[v] && i <= B; i++) {
            for (int j = 0; j <= sub[nxt] && i + j <= B; j++) {
                tmp[i + j] = max(tmp[i + j], mx[v][i] + mx[nxt][j]);
            }
        }
        copy(tmp, tmp + min(sub[v] + sub[nxt], B) + 1, mx[v]);
        sub[v] += sub[nxt];
    }
    for (auto pr : qr[v]) {
        if(pr.k >= K) {
            rep(i, 0, B + 1) {
                res[pr.idx] = max(res[pr.idx], mx[v][i] - i * pr.k);
            }
        }
    }
    for (int i = B; i >= 1; i--) mx[v][i] = mx[v][i - 1];
    mx[v][0] = 1;
}

mt19937 rng(2333);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> q;
    rep(i, 0, q) {
        int v, k;
        cin >> v >> k;
        v--;
        if(k >= K) qr[v].push_back({k, i});
        else q2[k].push_back({v, i});
    }
    dfs(0, -1);

    rep(k, 0, K) {
        calc(k);
    }
    solve(0, -1);
    rep(i, 0, q) {
        cout << res[i] << "\n";
    }

}