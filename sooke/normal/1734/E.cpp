#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 355;

int n, b[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) { b[i] = read(); }
    if (n == 2) {
        if (b[0] == b[1]) {
            printf("%d 0\n1 %d\n", b[0], b[1]);
        } else {
            printf("%d 0\n0 %d\n", b[0], b[1]);
        }
    } else {
        for (int i = 0; i < n; i++) { b[i] = (n + 1ll) / 2 * ((b[i] + n - i * i % n) % n) % n; }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", (b[i] + b[j] + i * j) % n);
            }
            printf("\n");
        }
    }
    return 0;
}