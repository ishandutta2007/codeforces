#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int p = 998244353;

inline int add(int x, int y) { x += y; return x >= p ? x - p : x; }
inline int sub(int x, int y) { x -= y; return x >= 0 ? x : x + p; }

const int N = 5005;

int n, ans, a[N], cnt[N], inv[N], f[N][N];

int main() {
    n = read(); inv[1] = 1;
    for (int i = 2; i <= n; i++) { inv[i] = 1ll * inv[p % i] * (p - p / i) % p; }
    for (int i = 1; i <= n; i++) { a[i] = read(); cnt[n + 1 - a[i]]++; }
    for (int i = 1, x; i <= n; i++) {
        x = cnt[i];
        for (int j = 2; j <= n; j++) {
            if (j == 2) { f[i][j] = x * (x - 1ll) % p * inv[n - j + 2] % p * inv[n - j + 1] % p; }
            f[i][j] = add(f[i][j], f[i - 1][j]);
            f[i][j] = add(f[i][j], 1ll * f[i - 1][j - 1] * x % p * inv[n - j + 1] % p);
        }
    }
    for (int i = 1; i <= n; i++) { ans = add(ans, f[n][i]); }
    printf("%d\n", ans);
    return 0;
}