#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, m, x, y, a[N];
char str[N];

bool check() {
    int cnt = 0, max = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] < x) { return false; }
        max = std::max(max, a[i]);
        if (a[i] >= y + y) { cnt++; }
    }
    if (cnt >= 2) { return false; }
    for (int i = 0; i <= max; i++) {
        int l = i;
        int r = max - i - x;
        if (r < 0) { continue; }
        if (l >= y + y) { continue; }
        if (r >= y + y) { continue; }
        if (l >= y && l < x) { continue; }
        if (r >= y && r < x) { continue; }
        int now = m;
        if (l >= x) { now++; }
        if (r >= x) { now++; }
        if (now & 1) { return true; }
    }
    return false;
}

int main() {
    for (int T = read(); T; T--) {
        x = read(); y = read(); m = 0;
        scanf("%s", str); n = strlen(str);
        for (int i = 0, len = 0; i <= n; i++) {
            if (str[i] == '.') {
                len++;
            } else {
                if (len >= y) { a[m++] = len; }
                len = 0;
            }
        }
        printf("%s\n", check() ? "YES" : "NO");
    }
    return 0;
}