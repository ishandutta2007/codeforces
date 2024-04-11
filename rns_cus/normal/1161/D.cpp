#include <bits/stdc++.h>
using namespace std;

#define N 4040

int n, m, vis[N];
const int mod = 998244353;
char s[N];

typedef pair <int, int> pii;

vector <pii> adj[N];

bool dfs(int u) {
    for (auto p : adj[u]) {
        int v = p.first, w = p.second;
        if (vis[v] >= 0) {
            if (vis[v] != (vis[u] ^ w)) return 0;
        }
        else {
            vis[v] = (vis[u] ^ w);
            if (!dfs(v)) return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int ans = 0;
    for (m = 1; m < n; m ++) {
        for (int i = 1; i <= 2 * n; i ++) vis[i] = -1, adj[i].clear();
        for (int i = 1; i <= n; i ++) {
            adj[i].push_back(pii(n + 1 - i, 0));
            if (s[i] != '?') {
                int x = s[i] - '0';
                adj[i].push_back(pii(n + i, x));
                adj[n+i].push_back(pii(i, x));
            }
            if (i > n - m) adj[n+i].push_back(pii(3 * n + 1 - m - i, 0));
        }
        int rlt = 1;
        for (int i = 1; i <= n - m; i ++) {
            if (vis[n+i] >= 0) {
                if (vis[n+i]) rlt = 0;
                continue;
            }
            vis[n+i] = 0;
            if (!dfs(n + i)) rlt = 0;
        }
        if (vis[2*n-m+1] >= 0) {
            if (vis[2*n-m+1] == 0) rlt = 0;
        }
        else {
            vis[2*n-m+1] = 1;
            if (!dfs(2 * n - m + 1)) rlt = 0;
        }
        for (int i = 1; i <= 2 * n; i ++) {
            if (vis[i] >= 0) continue;
            vis[i] = 0;
            if (dfs(i)) rlt = 2ll * rlt % mod;
            else rlt = 0;
        }
        ans += rlt;
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
}