#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e5 + 5;

int n, ans, max, cntl, cntr, a[N], sl[N], sr[N];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1, j; i <= n; i = j) {
        for (j = i + 1; j <= n && a[j - 1] <= a[j]; j++);
        for (int k = i; k < j; k++) { sl[k] = k - i; }
    }
    for (int i = n, j; i >= 1; i = j) {
        for (j = i - 1; j >= 1 && a[j] >= a[j + 1]; j--);
        for (int k = i; k > j; k--) { sr[k] = i - k; }
    }
    for (int i = 1; i <= n; i++) {
        max = std::max(max, sl[i]);
        max = std::max(max, sr[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (sl[i] == max) { cntl++; }
        if (sr[i] == max) { cntr++; }
    }
    for (int i = 1; i <= n; i++) {
        if (sl[i] == 0 && sr[i] == 0) { continue; }
        if (sl[i] == sr[i] && sl[i] % 2 == 0) {
            if (max > sl[i]) { continue; }
            if (cntl == 1 && cntr == 1) { ans++; }
        }
    }
    printf("%d\n", ans);
    return 0;
}