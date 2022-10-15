#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N];
long long ans;

bool check() {
    for (int i = 0; i < n; i++) {
        if (a[i] * 2ll > ans) { return true; }
    }
    return false;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); ans += a[i];
    }
    if (check()) { printf("NO\n"); return 0; }
    printf("%s\n", ans & 1 ? "NO" : "YES");
    return 0;   
}