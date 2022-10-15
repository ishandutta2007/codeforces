#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, ans, max, a[N], r[N], cnt[N];
bool used[N];

int main() {
    n = read(); read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); r[a[i]] = i;
    }
    for (int i = 0, j, k; i < n; i = j) {
        int m = r[a[i]]; used[a[i]] = true;
        for (j = i; j <= m; j++) {
            m = std::max(m, r[a[j]]);
        } max = 0;
        for (j = i; j <= m; j++) {
            max = std::max(max, ++cnt[a[j]]);
        } ans += j - i - max;   
    } printf("%d\n", ans);
    return 0;
} //