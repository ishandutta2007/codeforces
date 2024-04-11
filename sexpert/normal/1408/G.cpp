#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 1505;
const ll MOD = 998244353;

int n;
int a[MAXN][MAXN], cnt[MAXN], rep[MAXN], sz[MAXN], ord[MAXN], comps;
vector<ll> dp[MAXN];
ii edge[MAXN * MAXN];

int find(int u) {
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}

void fuse(vector<ll> &f, vector<ll> &g) {
    int n = f.size(), m = g.size();
    vector<ll> res(m + n - 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res[i + j] = (res[i + j] + f[i] * g[j]) % MOD;

    g.clear();
    f = res;
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) {
        ord[u]++;
        if(ord[u] == sz[u] * (sz[u] - 1) / 2)
            dp[u][1] = 1;
        return;
    }

    if(sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    ord[u] += ord[v] + 1;
    rep[v] = u;
    fuse(dp[u], dp[v]);
    if(ord[u] == sz[u] * (sz[u] - 1) / 2)
        dp[u][1] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            edge[a[i][j]] = {i, j};

    fill(sz, sz + MAXN, 1);
    iota(rep, rep + MAXN, 0);

    for(int i = 1; i <= n; i++)
        dp[i] = {0, 1};

    int tot = (n * (n - 1)) / 2;
    for(int w = 1; w <= tot; w++)
        join(edge[w][0], edge[w][1]);

    int u = find(1);
    for(int i = 1; i <= n; i++)
        cout << dp[u][i] << " ";
    cout << '\n';
}