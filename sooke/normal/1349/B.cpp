#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, min, a[N], pre[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        min = 1e9;
        bool flag = n == 1;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            if (a[i] == m) { ok = true; }
            a[i] = a[i] >= m ? 1 : 0;
            a[i] += a[i - 1];
            if (i - 2 >= 0) {
                min = std::min(min, a[i - 2] * 2 - (i - 2));
            }
            if (a[i] * 2 - i > min) { flag = true; }
        }
        printf("%s\n", flag && ok ? "yes" : "no");
    }
    return 0;
}