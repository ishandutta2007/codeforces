#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 200005;

int n, deg[N];

int main() {
    n = read();
    for (int i = 1; i < n; i++) { deg[read()]++; deg[read()]++; }
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 2) { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    return 0;
}