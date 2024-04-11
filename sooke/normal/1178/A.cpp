#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 105;

int n, cnt = 1, now, sum, a[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); sum += a[i];
    }
    now += a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] * 2 <= a[0]) { now += a[i]; cnt++; }
    }
    if (now * 2 > sum) {
        printf("%d\n", cnt);
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] * 2 <= a[0]) { printf("%d ", i + 1); }
        }
    } else { printf("0\n"); }
    return 0;
}