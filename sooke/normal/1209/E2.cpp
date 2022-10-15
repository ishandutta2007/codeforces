#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 12, M = 2e3 + 5, A = 1 << N;

int T, n, m, _m, all, f[A], g[A], w[A], sum[A], ctz[A], a[N][M], b[N][M], max[M], ord[M];

bool compare(int x, int y) { return max[x] > max[y]; }

inline int add(int x, int y) { return x + y >= n ? x + y - n : x + y; }

int main() {
    for (int T = read(); T; T--) {
        n = read(); _m = read(); all = 1 << n;
        for (int j = 0; j < _m; j++) {
            max[j] = 0; ord[j] = j;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < _m; j++) {
                b[i][j] = read(); max[j] = std::max(max[j], b[i][j]);
            }
        } std::sort(ord, ord + _m, compare); m = std::min(n, _m);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) { a[i][j] = b[i][ord[j]]; }
        }
        for (int i = 0; i < all; i++) {
            f[i] = 0; ctz[i] = __builtin_ctz(i);
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < all; i++) {
                g[i] = f[i]; w[i] = 0;
            }
            for (int k = 0; k < n; k++) {
                for (int i = 1; i < all; i++) {
                    sum[i] = sum[i ^ (1 << ctz[i])] + a[add(ctz[i], k)][j];
                    w[i] = std::max(w[i], sum[i]);
                }
            }   
            for (int i = 0; i < all; i++) {
                for (int s = i; s; s = i & (s - 1)) {
                    f[i] = std::max(f[i], g[i ^ s] + w[s]);
                }
            }
        } printf("%d\n", f[all - 1]);
    }
    return 0;
} //