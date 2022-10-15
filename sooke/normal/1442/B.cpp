#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 998244353;

const int N = 1e6 + 5;

int n, m, a[N], b[N], p[N], pre[N], nxt[N];
bool ban[N];

int solve() {
    int res = 1;
    for (int i = 0; i < m; i++) {
        int u = b[i];
        if (ban[pre[u]] && ban[nxt[u]]) { return 0; }
        ban[u] = false;
        if (ban[pre[u]]) {
            int v = nxt[u];
            nxt[pre[v]] = nxt[v];
            pre[nxt[v]] = pre[v];
        } else if (ban[nxt[u]]) {
            int v = pre[u];
            nxt[pre[v]] = nxt[v];
            pre[nxt[v]] = pre[v];
        } else {
            res = res * 2 % mod;
            nxt[pre[u]] = nxt[u];
            pre[nxt[u]] = pre[u];
        }
    }
    return res;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        for (int i = 1; i <= n; i++) { a[i] = read(); p[a[i]] = i; }
        for (int i = 0; i < m; i++) { b[i] = read(); b[i] = p[b[i]]; }
        for (int i = 1; i <= n + 1; i++) { pre[i] = i - 1; }
        for (int i = 0; i <= n; i++) { nxt[i] = i + 1; }
        for (int i = 0; i <= n + 1; i++) { ban[i] = false; }
        ban[0] = ban[n + 1] = true;
        for (int i = 0; i < m; i++) { ban[b[i]] = true; }
        printf("%d\n", solve());
    }
    return 0;
}