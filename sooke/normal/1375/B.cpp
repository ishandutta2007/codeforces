#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n, m;
std::vector<std::vector<int>> vec;

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = 0;
            if (i != 0) { k++; }
            if (j != 0) { k++; }
            if (i != n - 1) { k++; }
            if (j != m - 1) { k++; }
            if (vec[i][j] > k) { return false; }
            vec[i][j] = k;
        }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read();
        vec.resize(n);
        for (int i = 0; i < n; i++) {
            vec[i].resize(m);
            for (int j = 0; j < m; j++) {
                vec[i][j] = read();
            }
        }
        if (check()) {
            printf("YES\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", vec[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}