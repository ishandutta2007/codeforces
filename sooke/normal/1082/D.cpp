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
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 505;

int n, m, p = 1, ans, deg[maxN];
int numA, a[maxN], numB, b[maxN];

struct Edge { int u, v; } edg[maxN * maxN];

inline bool insert(int u) {
    while (p <= numA && !deg[a[p]]) { p++; }
    if (p > numA) { return false; }
    deg[a[p]]--; edg[++m] = (Edge) {a[p], u};
    return true;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { deg[i] = read(); }
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 1) { a[++numA] = i; } else { b[++numB] = i; }
    }
    for (int i = 2; i <= numA; i++) { edg[++m] = (Edge) {a[i - 1], a[i]}; }
    for (int i = 2; i < numA; i++) { deg[a[i]] -= 2; }
    if (numA > 1) { deg[a[1]]--; deg[a[numA]]--; }
    ans = numA - 1;
    if (numB >= 1) {
        if (numA < 1) { printf("NO\n"); return 0; }
        ans++; deg[a[1]]--; edg[++m] = (Edge) {a[1], b[1]};
    }
    if (numB >= 2) {
        if (numA < 1) { printf("NO\n"); return 0;}
        ans++; deg[a[numA]]--; edg[++m] = (Edge) {a[numA], b[2]};
    }
    for (int i = 3; i <= numB; i++) {
        if (!insert(b[i])) { printf("NO\n"); return 0;}
    }
    printf("YES %d\n%d\n", ans, m);
    for (int i = 1; i <= m; i++) { printf("%d %d\n", edg[i].u, edg[i].v); }
    return 0;
} ////