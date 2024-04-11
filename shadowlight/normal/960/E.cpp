#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <ll> a;
vector <ll> sz;
vector <vector <int> > gr;

vector <ll> dp[2], res[2];
ll ans = 0, n;

void sz_dfs(ll v, ll p) {
    sz[v] = 1;
    for (ll u : gr[v]) {
        if (u == p) continue;
        sz_dfs(u, v);
        sz[v] += sz[u];
    }
}

void add(ll &x, ll y) {
    x = (x + y) % INF;
}

void dfs(ll v, ll p) {
    dp[0][v] = 1;
    for (ll u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
        add(dp[0][v], dp[1][u]);
        add(dp[1][v], dp[0][u]);
        add(res[0][v], dp[1][u] * (n - sz[u]));
        add(res[1][v], dp[0][u] * (n - sz[u]));
    }
    add(res[0][v], n);
}

void dfs1(ll v, ll p, ll all0, ll all1) {
    ll sum[2];
    sum[0] = (all1 + 1) % INF;
    sum[1] = all0;
    add(res[0][v], all1 * sz[v]);
    add(res[1][v], all0 * sz[v]);
    for (ll u : gr[v]) {
        if (u == p) continue;
        add(sum[0], dp[1][u]);
        add(sum[1], dp[0][u]);
    }
    for (ll u : gr[v]) {
        if (u == p) continue;
        add(sum[0], -dp[1][u]);
        add(sum[1], -dp[0][u]);
        dfs1(u, v, sum[0], sum[1]);
        add(sum[0], dp[1][u]);
        add(sum[1], dp[0][u]);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < 2; i++) {
        dp[i].resize(n, 0);
        res[i].resize(n, 0);
    }
    sz.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    sz_dfs(0, -1);
    dfs(0, -1);
    dfs1(0, -1, 0, 0);
    for (ll i = 0; i < n; i++) {
        //cout << i << " " << dp[0][i] << " " << dp[1][i] << "\n";
        add(ans, a[i] * res[0][i]);
        add(ans, -a[i] * res[1][i]);
        add(ans, 2 * INF);
    }
    cout << ans;
}