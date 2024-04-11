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

const int N = 200005;

int n, anc0[N], anc1[N], siz0[N], siz1[N];
long long ans;

int findAnc0(int u) { return anc0[u] == u ? u : anc0[u] = findAnc0(anc0[u]); }
int findAnc1(int u) { return anc1[u] == u ? u : anc1[u] = findAnc1(anc1[u]); }

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { anc0[i] = anc1[i] = i; }
    for (int i = 2; i <= n; i++) {
        int u = read(), v = read(), w = read();
        if (w) {
            u = findAnc1(u); v = findAnc1(v);
            if (u != v) { anc1[u] = v; }
        } else {
            u = findAnc0(u); v = findAnc0(v);
            if (u != v) { anc0[u] = v; }
        }
    }
    for (int i = 1; i <= n; i++) { siz0[findAnc0(i)]++; siz1[findAnc1(i)]++; }
    for (int i = 1; i <= n; i++) { ans += 1ll * siz0[anc0[i]] * siz1[anc1[i]]; }
    printf("%I64d\n", ans - n);
    return 0;
}