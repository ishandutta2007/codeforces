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

const int N = 500005;

int n, m, anc[N], siz[N];

int findAnc(int u) { return anc[u] == u ? u : anc[u] = findAnc(anc[u]); }

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) { anc[i] = i; }
    for (int k, u, v; m; m--) {
        k = read();
        if (k) {
            u = read();
            for (int i = 2; i <= k; i++) {
                v = read();
                if (findAnc(u) != findAnc(v)) { anc[findAnc(u)] = findAnc(v); }
            }
        }
    }
    for (int i = 1; i <= n; i++) { siz[findAnc(i)]++; }
    for (int i = 1; i <= n; i++) { printf("%d ", siz[findAnc(i)]); }
    return 0;
}