#include <cstdio>

int n, m, p[1000005];

void print(int x, int y) { printf("%d %d\n", x, y); }

void solve(int l, int r) {
    if (l > r) { return; }
    int y = r, k = l ^ r;
    for (int i = 0; i < n; i++) { print(p[i], y ^= k); }
    if (k) {
        for (int i = n; i; i--) { print(p[i - 1], y ^= k); }
        solve(l + 1, r - 1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) { p[i] = i & 1 ? n - i / 2 : i / 2 + 1; }
    solve(1, m);
    return 0;
}