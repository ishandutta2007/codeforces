#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

int n, a[N];

int main() {
    for (int T = read(); T; T--) {
        n = read();
        bool allz = true, midz = false;
        for (int i = 0; i < n; i++) {
            a[i] = read();
            if (a[i] != 0) { allz = false; }
        }
        int l = -1, r = n;
        while (l + 1 < n && a[l + 1] == 0) { l++; }
        while (r - 1 >= 0 && a[r - 1] == 0) { r--; }
        for (int i = 0; i < n; i++) {
            if (a[i] == 0 && l < i && i < r) { midz = true; }
        }
        if (allz) {
            printf("0\n");
        } else if (midz) {
            printf("2\n");
        } else {
            printf("1\n");
        }
    }
    return 0;
}