#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, cnt, ans, a[N];

int main() {
    n = read(); a[0] = -1;
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) { cnt += a[i - 1] == a[i]; }
    if (cnt >= 2) { printf("cslnb\n"); return 0; }
    if (cnt == 1) {
        ans = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] == a[i]) {
                if (a[i] == 0) { printf("cslnb\n"); return 0; } else { a[i]--; break; }
            }
        }
        std::sort(a + 1, a + n + 1);
    }
    cnt = 0;
    for (int i = 2; i <= n; i++) { cnt += a[i - 1] == a[i]; }
    if (cnt >= 1) { printf("cslnb\n"); return 0; }
    for (int i = 1; i <= n; i++) {
        ans ^= std::max(a[i] - a[i - 1] - 1, 0);
        a[i] = std::min(a[i], a[i - 1] + 1);
    }
    printf("%s\n", ans & 1 ? "sjfnb" : "cslnb");
    return 0;
}