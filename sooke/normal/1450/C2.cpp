#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 305;

int n, k;
char c[N][N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", c[i]);
            for (int j = 0; j < n; j++) {
                k += c[i][j] != '.';
            }
        }
        bool ok = false;
        for (int d = 0; d < 3; d++) {
            for (int e = 0; e < 3; e++) {
                if (ok) { continue; }
                if (d == e) { continue; }
                int k0 = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((i + j) % 3 != d) { continue; }
                        k0 += c[i][j] == 'X';
                    }
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if ((i + j) % 3 != e) { continue; }
                        k0 += c[i][j] == 'O';
                    }
                }
                if (k0 <= k / 3) {
                    ok = true;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if ((i + j) % 3 != d) { continue; }
                            if (c[i][j] == 'X') { c[i][j] = 'O'; }
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if ((i + j) % 3 != e) { continue; }
                            if (c[i][j] == 'O') { c[i][j] = 'X'; }
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        printf("%s\n", c[i]);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}