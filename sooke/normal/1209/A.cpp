#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, m, a[N], b[N];

bool check(int x) {
    for (int i = 0; i < m; i++) {
        if (x % b[i] == 0) { return false; }
    } return true;
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    std::sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (check(a[i])) { b[m++] = a[i]; }
    } printf("%d\n", m);
    return 0;
} //