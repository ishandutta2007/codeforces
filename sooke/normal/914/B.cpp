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

const int maxN = 100005;

int n, cnt[maxN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { cnt[read()]++; }
    for (int i = 100000; i; i--) {
        if (cnt[i] & 1) { printf("Conan\n"); return 0; }
    }
    printf("Agasa\n");
    return 0;
} ////