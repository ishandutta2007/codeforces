#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n;
std::map<int, int> f;

int main() {
    for (int T = read(); T; T--) {
        n = read(); f.clear();
        for (int i = 0; i < n; i++) {
            int x = read();
            f[x]++;
        }
        for (int i = 2; i <= 2048; i *= 2) {
            f[i] += f[i / 2] / 2;
        }
        printf("%s\n", f[2048] ? "YES" : "NO");
    }
    return 0;
} //