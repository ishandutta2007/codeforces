#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, sum, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = read(); sum += a[i];
        }
        if (sum == 0) { printf("NO\n"); continue; }
        if (sum < 0) {
            std::sort(a, a + n);
        } else {
            std::sort(a, a + n);
            std::reverse(a, a + n);
        }
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}