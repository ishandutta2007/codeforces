#include <cstdio>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

int m, n, ans;

int main() {
    m = read(); n = read();
    for (int i = n - 1; ~i; i--) {
        int t = read();
        if (i == 0) { ans = (ans + t) % 2; } else { ans = (ans + t * m) % 2; }
    }
    printf("%s\n", ans & 1 ? "odd" : "even");
    return 0;
} // Sooke