#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}
inline char readOpt() {
    char c = getchar();
    while (c != '<' && c != '=' && c != '>') { c = getchar(); }
    return c;
}

const int maxN = 2005;

int n, m, ts, vol, l = 1, r, dfn[maxN], low[maxN], stack[maxN], col[maxN], deg[maxN], q[maxN ], dis[maxN], e[maxN][maxN];
char c[maxN][maxN];
bool ins[maxN];

void tarjan(int u) {
    dfn[u] = low[u] = ++ts; stack[++vol] = u;
    int tmp = vol; ins[u] = true;
    for (int i = 1; i <= n + m; i++) {
        if (c[u][i] == '=') {
            if (!dfn[i]) {
                tarjan(i);
                low[u] = std::min(low[u], low[i]);
            } else if (ins[i]) {
                low[u] = std::min(low[u], dfn[i]);
            }
        }
    }
    if (dfn[u] == low[u]) {
        for (int i = tmp; i <= vol; i++) {
            ins[stack[i]] = false;
            col[stack[i]] = u;
        }
        vol = tmp - 1;
    }
}

int main() {
    n = read(); m = read();
    memset(c, ' ', sizeof(c));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            c[i][n + j] = readOpt();
            if (c[i][n + j] == '=') { c[n + j][i] = '='; }
            if (c[i][n + j] == '>') { c[n + j][i] = '<'; c[i][n + j] = ' '; }
        }
    }
    for (int i = 1; i <= n + m; i++) {
        if (!dfn[i]) { tarjan(i); }
    }
    for (int i = 1, u; i <= n + m; i++) {
        u = col[i];
        for (int j = 1, v; j <= n + m; j++) {
            v = col[j];
            if (c[i][j] == '<') {
                if (u == v) {
                    printf("No\n"); return 0;
                } else { e[u][v]++; deg[v]++; }
            }
        }
    }
    for (int i = 1; i <= n + m; i++) {
        if (col[i] == i && !deg[i]) { q[++r] = i; }
    }
    for (int u, v; l <= r; l++) {
        u = q[l];
        for (int i = 1; i <= n + m; i++) {
            if (e[u][i]) {
                v = i; deg[v] -= e[u][i];
                if (!deg[v]) { q[++r] = v; } dis[v] = std::max(dis[v], dis[u] + 1);
            }
        }
    }
    for (int i = 1; i <= n + m; i++) {
        if (col[i] == i && deg[i]) { printf("No\n"); return 0; }
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++) { printf("%d ", dis[col[i]] + 1); } printf("\n");
    for (int i = 1; i <= m; i++) { printf("%d ", dis[col[n + i]] + 1); }
    return 0;
}