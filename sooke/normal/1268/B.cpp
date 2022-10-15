#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N];
long long ans[2];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        ans[i & 1] += a[i] >> 1;
        ans[i & 1 ^ 1] += a[i] + 1 >> 1;
    }
    printf("%I64d\n", std::min(ans[0], ans[1]));
    return 0;
}