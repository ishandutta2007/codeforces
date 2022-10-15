#include <cstdio>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxN = 100005;

int n, m, k, a[maxN], b[maxN];
long long ans;

int main() {
    n = read(); m = read(); k = n - read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = 1; i < n; i++) { b[i] = a[i + 1] - a[i]; }
    std::sort(b + 1, b + n);
    for (int i = 1; i <= k; i++) { ans += b[i]; }
    printf("%I64d\n", ans + n - k);
    return 0;
} // Sooke