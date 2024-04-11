#include <cstdio>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxN = 100005;

int n, a[maxN], b[maxN], c[maxN], d[maxN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 1; i < n; i++) { b[i] = a[i + 1] - a[i]; }
    for (int i = 1; i <= n; i++) { c[i] = read(); }
    for (int i = 1; i < n; i++) { d[i] = c[i + 1] - c[i]; }
    std::sort(b + 1, b + n); std::sort(d + 1, d + n);
    bool flag = a[1] == c[1] && a[n] == c[n];
    for (int i = 1; i < n; i++) { flag &= b[i] == d[i]; }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
} // Sooke