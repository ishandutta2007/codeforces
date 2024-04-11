#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e3 + 5;

int n, ans, a[N], b[N];
char str[N];

int main() {
    n = read(); scanf("%s", &str);
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read();
    }
    for (int i = 0; i < 10000; i++) {
        int now = 0;
        for (int j = 0; j < n; j++) {
            if (i >= b[j] && (i - b[j]) % a[j] == 0) { str[j] ^= 1; }
            now += str[j] == '1';
        } ans = std::max(ans, now);
    } printf("%d\n", ans);
    return 0;
} //