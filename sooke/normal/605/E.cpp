#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e3 + 5;

int n;
bool vis[N];
double e[N][N], f[N], g[N], p[N];
std::priority_queue<std::pair<double, int>> que;

int main() {
    n = read();
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            e[u][v] = read() / 100.0;
        }
    }
    for (int u = 1; u < n; u++) { f[u] = p[u] = 1; }
    que.push({0, n});
    while (true) {
        int u = que.top().second;
        if (u == 1) { printf("%f\n", -que.top().first); break; }
        que.pop();
        if (vis[u]) { continue; }
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (g[u] > 0) { f[v] += f[u] / g[u] * p[v] * e[v][u]; }
            g[v] += p[v] * e[v][u]; p[v] *= 1 - e[v][u];
            que.push({-f[v] / g[v], v});
        }
    }
    return 0;
}