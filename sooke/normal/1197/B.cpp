#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N];
bool pre[N], suf[N];

bool check() {
    for (int i = 0; i < n; i++) {
        if (pre[i] && suf[i]) { return true; }
    }
    return false;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }   
    pre[0] = suf[n - 1] = true;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1];
        if (a[i - 1] >= a[i]) { pre[i] = false; }
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (a[i + 1] >= a[i]) { suf[i] = false; }
    }
    printf("%s\n", check() ? "YES" : "NO");
    return 0;
}