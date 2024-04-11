#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
const int N = 200000 + 10;

int n; vector<int> g[N];

LL val[N];
LL sz[N], cnt1[N], cnt2[N], fg[N];
LL ans = 0;

void get_sz(int u, int p) {
    sz[u] = 1; cnt1[u] = 1;   
    for (int i = 0; i < g[u].size(); i ++) {
        int v = g[u][i];
        if (v == p) continue;
        fg[v] = 1 - fg[u];
        get_sz(v, u);

        sz[u] += sz[v];
        cnt1[u] += cnt2[v];
        cnt2[u] += cnt1[v];
    }    
}

void dfs(int u, int p) {  

    int tot1 = fg[u] ? cnt2[1] : cnt1[1];
    int tot2 = fg[u] ? cnt1[1] : cnt2[1];

    ans += cnt1[u] * (n - sz[u] + 1) % MOD * val[u] % MOD;    // down to up
    ans -= cnt2[u] * (n - sz[u] + 1) % MOD * val[u] % MOD;

    ans += (tot1 - cnt1[u] + 1) * sz[u] % MOD * val[u] % MOD; // up to down
    ans -= (tot2 - cnt2[u]) * sz[u] % MOD * val[u] % MOD;   
    ans -= val[u];

    for (int i = 0; i < g[u].size(); i ++) {
        int v = g[u][i];
        if (v == p) continue;

        dfs(v, u);

        ans += cnt2[v] * (sz[u] - sz[v] - 1) % MOD * val[u] % MOD;
        ans -= cnt1[v] * (sz[u] - sz[v] - 1) % MOD * val[u] % MOD;

        ans = (ans % MOD + MOD) % MOD;
    }

}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &val[i]);
    }
    for (int i = 1; i < n; i ++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    get_sz(1, -1);
    dfs(1, -1);
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}