#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 100005;

int n, l = -1e9, r = 1e9, a[maxN];
std::string s;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    std::cin >> s; s = " " + s;
    for (int i = 5; i <= n; i++) {
        if (s[i - 1] == '0') {
            if (s[i] == '1') {
                for (int j = 0; j <= 4; j++) { l = std::max(l, a[i - j] + 1); }
            }
        } else {
            if (s[i] == '0') {
                for (int j = 0; j <= 4; j++) { r = std::min(r, a[i - j] - 1); }
            }
        }
    }
    printf("%d %d\n", l, r);
    return 0;
}