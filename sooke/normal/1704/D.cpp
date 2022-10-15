#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, m;
long long b[N];
std::vector<long long> a[N];

int main() {
    int T = read();
    for (; T; T--) {
        n = read(); m = read();
        long long min = -1;
        for (int i = 0; i < n; i++) {
            a[i].resize(m); b[i] = 0;
            for (int j = 0; j < m; j++) {
                a[i][j] = read();
                b[i] += a[i][j] * j;
            }
            if (min == -1 || min > b[i]) { min = b[i]; }
        }
        for (int i = 0; i < n; i++) {
            if (min != b[i]) {
                printf("%d %lld\n", i + 1, b[i] - min);
            }
        }
    }
    return 0;
}