#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1000005;

int r, c, k, a[N], b[N];

int main() {
    r = read(); c = read();
    if (r == 1 && c == 1) { printf("0\n"); return 0; }
    if (r == 1) {
        a[0] = 1;
        for (int i = 0; i < c; i++) { b[i] = i + 2; }
    } else if (c == 1) {
        b[0] = 1;
        for (int i = 0; i < r; i++) { a[i] = i + 2; }
    } else {
        for (int i = 0; i < r; i++) { a[i] = ++k; }
        for (int i = 0; i < c; i++) { b[i] = ++k; }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) { printf("%d ", a[i] * b[j]); }
        printf("\n");
    }
    return 0;
}