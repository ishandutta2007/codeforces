#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n;
vector <int> adj[N];
const int mod = 998244353;

int inv(int x) {
    int rlt = 1, n = mod - 2;
    while (n) {
        if (n & 1) rlt = 1ll * rlt * x % mod;
        x = 1ll * x * x % mod, n >>= 1;
    }
    return rlt;
}

int dp0[N], dp1[N], dp2[N];

inline void add(int &x, long long y) {
    x = (x + y) % mod;
}

void dfs(int u, int pa = 0) {
    bool aft = 0;
    int tot = 1, cur = 1, ful = 1;
    for (auto v : adj[u]) {
        if (v == pa) {
            aft = 1;
            dp1[u] = cur;
            continue;
        }
        dfs(v, u);
        int c = inv(dp0[v] + dp2[v]);
        if (!aft) add(dp0[u], 1ll * cur * dp2[v] % mod * c);
        else add(dp2[u], 1ll * cur * dp2[v] % mod * c);
        ful = 1ll * ful * (dp0[v] + dp1[v]) % mod;
        tot = 1ll * tot * (dp0[v] + dp2[v]) % mod;
        cur = 1ll * cur * (dp0[v] + dp1[v]) % mod;
        cur = 1ll * cur * c % mod;
    }
    if (!aft) dp1[u] = cur;
    dp0[u] = 1ll * dp0[u] * tot % mod;
    dp1[u] = 1ll * dp1[u] * tot % mod;
    dp2[u] = 1ll * dp2[u] * tot % mod;
    add(dp2[u], ful);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i ++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    printf("%d\n", (dp0[1] + dp1[1]) % mod);

    return 0;
}