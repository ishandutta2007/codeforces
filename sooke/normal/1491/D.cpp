#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int q, u, v;

bool check() {
    for (int i = 30; i >= 0; i--) {
        if (u >> i & 1) {
            int w = u + (1 << i);
            if (w <= v) {
                u = w;
                for (; (1ll << i) <= u; i++);
            }
        }
    }
    return u == v;
}

int main() {
    q = read();
    for (; q; q--) {
        u = read(); v = read();
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}