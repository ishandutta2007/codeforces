#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005;

int n, m, fa[maxN];
bool r[maxN];
std::vector<int> vec[maxN];

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
inline int merge(int u, int v) { fa[find(u)] = find(v); }

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) { r[i] = read(); }
    for (int i = 1; i <= m; i++) {
        int k = read();
        for (int j = 1; j <= k; j++) { vec[read()].push_back(i); }
        fa[i] = i, fa[m + i] = m + i;
    }
    for (int i = 1; i <= n; i++) {
        if (r[i]) {
            if (find(vec[i][0]) == find(m + vec[i][1])) { printf("NO\n"); return 0; }
            if (find(vec[i][0]) != find(vec[i][1])) {
                merge(vec[i][0], vec[i][1]), merge(vec[i][0] + m, vec[i][1] + m);
            }
        } else {
            if (find(vec[i][0]) == find(vec[i][1])) { printf("NO\n"); return 0; }
            if (find(vec[i][0]) != find(m + vec[i][1])) {
                merge(vec[i][0], m + vec[i][1]), merge(m + vec[i][0], vec[i][1]);
            }
        }
    }
    printf("YES\n");
    return 0;
}