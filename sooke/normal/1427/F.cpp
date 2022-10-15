#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n;
std::vector<int> a, b, f;

int main() {
    n = read();
    a = std::vector<int> (n * 6, 0);
    std::iota(a.begin(), a.end(), 1);
    b = std::vector<int> (n * 6, 1);
    for (int i = 0; i < n * 3; i++) {
        int x = read(); x--;
        b[x] = 0;
    }
    for (int o = 0; !a.empty(); o ^= 1) {
        f.resize(a.size());
        for (int i = 0, j; i < b.size(); i = j) {
            for (j = i; j < b.size() && b[i] == b[j]; j++);
            if ((j - i) % 3 != 0) { break; }
            for (j = i; j < b.size() && b[i] == b[j]; j++) { f[j] = 1; }
        }
        for (int i = b.size() - 1, j; i >= 0; i = j) {
            for (j = i; j >= 0 && b[i] == b[j]; j--);
            if ((i - j) % 3 != 0) { break; }
            for (j = i; j >= 0 && b[i] == b[j]; j--) { f[j] = 1; }
        }
        int p = -1, q;
        for (int i = 2; i < b.size(); i++) {
            if (b[i - 2] == o && b[i - 1] == o && b[i] == o) {
                if (!f[i]) { p = i; } q = i;
            }
        }
        if (p == -1) { p = q; }
        printf("%d %d %d\n", a[p - 2], a[p - 1], a[p]);
        a.erase(a.begin() + p - 2, a.begin() + p + 1);
        b.erase(b.begin() + p - 2, b.begin() + p + 1);
    }
    return 0;
}