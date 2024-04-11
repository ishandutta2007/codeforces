#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, k, b[N];
std::vector<int> a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = 0;
        bool lflag = false, rflag = false;
        for (int i = 0; i <= n + 1; i++) { a[i].clear(); }
        for (int i = 1; i <= n; i++) {
            b[i] = read();
            if (b[i] < i) {
                k = std::max(k, b[i]);
            } else {
                k = std::max(k, i);
            }
            if (b[i] == n + 1) { lflag = true; }
            if (b[i] == 0) { rflag = true; }
            a[b[i]].push_back(i);
        }
        printf("%d\n", k);
        if (k == 0 || k == n) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", i);
            }
            printf("\n");
            continue;
        }
        std::vector<int> e;
        int p = -1;
        if (lflag) { p = n + 1; }
        if (rflag) { p = 0; }
        for (; ; ) {
            int z = -1;
            for (auto x : a[p]) {
                if (!a[x].empty()) {
                    z = x;
                }
            }
            for (auto x : a[p]) {
                if (x != z) { e.push_back(x); }
            }
            for (auto x : a[p]) {
                if (x == z) { e.push_back(x); }
            }
            if (z == -1) { break; }
            p = z;
        }
        for (auto x : e) { printf("%d ", x); }
        printf("\n");
    }
    return 0;
}