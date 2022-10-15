#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

const int maxN = 100005;

int n, m, dec, a[maxN];

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    std::sort(a + 1, a + n + 1);
    for (int i = 1, j = 1; i <= m; i++) {
        if (j > n) { printf("0\n"); continue; }
        a[j] -= dec; 
        if (a[j] == 0) { j++; i--; continue; }
        dec += a[j];
        printf("%d\n", a[j++]);
    }
    return 0;
} ////