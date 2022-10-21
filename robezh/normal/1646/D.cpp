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
//typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n;
vi G[N];
pll dp[N][2];
ll res[N];

pll operator + (const pll p1, const pll p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
void dfs(int v, int p) {
    pll sum0 = {0, 0}, sum1 = {0, 0};
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        sum0 = sum0 + min(dp[nxt][0], dp[nxt][1]);
        sum1 = sum1 + dp[nxt][0];
    }
    dp[v][0] = sum0 + pll{0, 1};
    dp[v][1] = sum1 + pll{-1, sz(G[v])};
}

void solve(int v, int c, int p) {
    res[v] = (c ? sz(G[v]) : 1);
//    if(c) cout << "choose: " << v << endl;
    for (int nxt : G[v]) {
        if(nxt == p) continue;
        if(c || dp[nxt][0] < dp[nxt][1]) {
            solve(nxt, 0, v);
        } else {
            solve(nxt, 1, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n == 2) {
        cout << 2 << " " << 2 << '\n';
        cout << 1 << " " << 1 << '\n';
        return 0;
    }
    dfs(0, -1);
    if(dp[0][0] < dp[0][1]) solve(0, 0, -1);
    else solve(0, 1, -1);
    pll rs = min(dp[0][0], dp[0][1]);
    cout << -rs.first << " " << rs.second << '\n';
    rep(i, 0, n) cout << res[i] << " ";
    cout << '\n';
}