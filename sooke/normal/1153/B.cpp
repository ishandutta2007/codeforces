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
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int N = 105;

int n, m, h, a[N], b[N], f[N][N];

int main() {
    n = read(); m = read(); h = read();
    for (int i = 1; i <= m; i++) { a[i] = read(); }
    for (int i = 1; i <= n; i++) { b[i] = read(); }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = read();
            if (f[i][j]) {
                printf("%d ", std::min(a[j], b[i]));
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}