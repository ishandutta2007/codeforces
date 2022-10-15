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

const int maxN = 150005;

int n, arc[maxN], nxt[maxN], head[maxN], tail[maxN];

inline int find(int u) { return arc[u] == u ? u : arc[u] = find(arc[u]); }

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { arc[i] = i; head[i] = tail[i] = i; }
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read();
        u = find(u); v = find(v); arc[v] = u;
        nxt[tail[u]] = head[v]; tail[u] = tail[v];
    }
    for (int i = head[find(1)]; ; i = nxt[i]) {
        printf("%d ", i);
        if (i == tail[find(1)]) { break; }
    }
    return 0;
}