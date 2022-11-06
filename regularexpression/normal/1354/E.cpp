#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

const int N = 5e3 + 7;

int n, n1, n2, n3, m;
vector<int> g[N];
int col[N], black, white;
vector<int> vs;
bool dp[N][N];

void die() {
    cout << "NO\n";
    exit(0);
}

void dfs(int v) {
    if (col[v]) black++; else white++;
    vs.pb(v);
    for (auto u : g[v]) {
        if (col[u] == col[v]) die();
        if (col[u] == -1) {
            col[u] = col[v] ^ 1;
            dfs(u);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> n1 >> n2 >> n3;
    while (m--) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].pb(u);
        g[u].pb(v);
    }
    memset(col, 255, sizeof(col));
    vector<pair<vector<int>, pair<int, int>>> cs;
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            vs.clear();
            black = white = 0;
            col[i] = 0;
            dfs(i);
            cs.pb({vs, {black, white}});
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < sz(cs); i++) {
        for (int j = 0; j <= n2; j++) {
            if (!dp[i][j]) continue;
            if (j + cs[i].y.x <= n2) dp[i + 1][j + cs[i].y.x] = 1;
            if (j + cs[i].y.y <= n2) dp[i + 1][j + cs[i].y.y] = 1;
        }
    }
    if (!dp[sz(cs)][n2]) die();
    vector<int> o, e;
    for (int i = sz(cs) - 1; i >= 0; i--) {
        if (n2 >= cs[i].y.x && dp[i][n2 - cs[i].y.x]) {
            for (auto v : cs[i].x) {
                if (col[v]) e.pb(v); else o.pb(v);
            }
            n2 -= cs[i].y.x;
        } else {
            for (auto v : cs[i].x) {
                if (col[v]) o.pb(v); else e.pb(v);
            }
            n2 -= cs[i].y.y;
        }
    }
    string ans(n, '0');
    for (int i = 0; i < n1; i++) ans[o[i]] = '1';
    for (int i = n1; i < sz(o); i++) ans[o[i]] = '3';
    for (auto v : e) ans[v] = '2';
    cout << "YES\n" << ans << '\n';
    return 0;
}