#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 2e5 + 5;

int n, m;
char s[N], t[N], str[N];

bool check() {
    int x = 0, y = 0, p = 0, q = 0;
    for (int i = 1; i <= n; i++) {
        if (str[i] == '1') {
            x++;
            if (x <= m / 2) {
                s[i] = t[i] = '('; p++; q++;
            } else {
                s[i] = t[i] = ')'; p--; q--;
            }
        } else {
            y ^= 1;
            if (y == 1) {
                s[i] = '('; t[i] = ')'; p++; q--;
            } else {
                s[i] = ')'; t[i] = '('; p--; q++;
            }
        }
        if (p < 0 || q < 0) { return false; }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = 0;
        scanf("%s", str + 1);
        for (int i = 1; i <= n; i++) {
            m += str[i] == '1';
        }
        if (m % 2 == 1) { puts("NO"); continue; }
        if (!check()) { puts("NO"); continue; }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            putchar(s[i]);
        }
        putchar('\n');
        for (int i = 1; i <= n; i++) {
            putchar(t[i]);
        }
        putchar('\n');
    }
    return 0;
}