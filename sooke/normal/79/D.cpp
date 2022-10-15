#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 10005;

int n, k, m, num, a[maxN], b[maxN], dis[21][maxN], f[1 << 21], lg2[1 << 21];
bool g[maxN], inq[maxN];
std::queue<int> q;

void spfa(int s) {
    memset(dis[s], 30, sizeof(dis[s]));
    dis[s][a[s]] = 0, q.push(a[s]), inq[a[s]] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 1; i <= m; i++) {
            if (u + b[i] <= n && dis[s][u + b[i]] > dis[s][u] + 1) {
                dis[s][u + b[i]] = dis[s][u] + 1;
                if (!inq[u + b[i]]) { inq[u + b[i]] = true, q.push(u + b[i]); }
            }
            if (u - b[i] >= 1 && dis[s][u - b[i]] > dis[s][u] + 1) {
                dis[s][u - b[i]] = dis[s][u] + 1;
                if (!inq[u - b[i]]) { inq[u - b[i]] = true, q.push(u - b[i]); }
            }
        }
        inq[u] = false;
    }
}

int main() {
    n = read() + 1, k = read(), m = read();
    for (int i = 1; i <= k; i++) { int u = read(); g[u] ^= 1, g[u + 1] ^= 1; }
    for (int i = 1; i <= n; i++) { if (g[i]) { a[num++] = i; } }
    for (int i = 1; i <= m; i++) { b[i] = read(); }
    for (int i = 0; i < num; i++) { spfa(i), lg2[1 << i] = i; }
    memset(f, 60, sizeof(f));
    f[0] = 0;
    for (int i = 3; i < (1 << num); i++) {
        int u = lg2[i & -i];
        for (int j = i ^ (1 << u); j; j ^= j & -j) {
            int v = lg2[j & -j];
            f[i] = std::min(f[i], f[i ^ (1 << u) ^ (1 << v)] + dis[u][a[v]]);
        }
    }
    if (f[(1 << num) - 1] <= 50000000) { printf("%d\n", f[(1 << num) - 1]); } else { printf("-1\n"); }
    return 0;
}