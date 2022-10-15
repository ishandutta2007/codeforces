#include <bits/stdc++.h>

const int N = 1e3 + 5;

int n, num, a[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n / 4; i++) {
        for (int j = 0; j < n / 4; j++) {
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    a[i << 2 | x][j << 2 | y] = num++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { printf("%d ", a[i][j]); }
        printf("\n");
    }
    return 0;
} // submit by luogu