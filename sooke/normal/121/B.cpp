#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar();
    while (c < '0' || c > '9') { c = getchar(); }
    return c & 15;
}

const int maxN = 2000005;

int n, k, a[maxN], used[maxN];

int main() {
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 1; i <= n; i++) { a[i] = read(); }
        for (int i = 1, j = 1; i < n && j <= k; i++) {
            if (i > 0 && a[i] == 4 && a[i + 1] == 7) {
                used[j++] = i;
                if (j > 3 && used[j - 3] == i) {
                    if (i & 1) {
                        if ((k - j) & 1) { a[i + 1] = 4; } else { a[i + 1] = 7; }
                    } else {
                        if ((k - j) & 1) { a[i] = 7; } else { a[i] = 4; }
                    } 
                    break;
                }
                if (i & 1) { a[i + 1] = 4; } else { a[i] = 7; }
                i -= 3;
            }
        }
        for (int i = 1; i <= n; i++) { printf("%d", a[i]); }
        printf("\n");
    }
    return 0;
}