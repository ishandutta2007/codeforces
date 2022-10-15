#include <cstdio>
#include <map>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

int q, n, m;
std::map<int, int> map;

int main() {
    for (int i = 2; i <= 25; i++) {
        n = (1 << i) - 1; map[n] = 1;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) { map[n] = n / j; break; }
        }
    }
    for (q = read(); q; q--) {
        n = read();
        if (map[n]) { printf("%d\n", map[n]); } else {
            m = 1;
            while (n >= m) { m <<= 1; }
            printf("%d\n", m - 1);
        }
    }
    return 0;
} // Sooke