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
    char c = getchar(); int x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

const int maxN = 200005;

int n, ans, a[maxN];
long long pre[2][maxN], suf[2][maxN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 1; i <= n; i++) {
        pre[0][i] = pre[0][i - 1]; pre[1][i] = pre[1][i - 1];
        pre[i & 1][i] += a[i];
    }
    for (int i = n; i; i--) {
        suf[0][i] = suf[0][i + 1]; suf[1][i] = suf[1][i + 1];
        suf[i & 1][i] += a[i];
    }
    for (int i = 1; i <= n; i++) {
        ans += pre[0][i - 1] + suf[1][i + 1] == pre[1][i - 1] + suf[0][i + 1];
    }
    printf("%d\n", ans);
    return 0;
}