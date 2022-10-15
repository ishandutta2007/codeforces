#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n;
long long a[N];

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
    }
    printf("1 1\n%d\n", -a[0]);
    if (n > 1) {
        a[0] = 0;
        printf("2 %d\n", n);
        for (int i = 1; i < n; i++) {
            printf("%lld ", 1ll * a[i] * (n - 1));
        }
        printf("\n");
        printf("1 %d\n", n);
        for (int i = 0; i < n; i++) {
            printf("%lld ", -1ll * a[i] * n);
        }
    } else {
        printf("1 1\n%d\n", 0);
        printf("1 1\n%d\n", 0);
    }
    return 0;
}