#include <bits/stdc++.h>

const int N = 1e3 + 5;

int n, m;
long long ans;
char str[N][N];

inline int get(int j, char c) {
    int res = 0;
    for (int i = 0; i < n; i++) { res += str[i][j] == c; }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) { scanf("%s", str[i]); }
    for (int i = 0; i < m; i++) {
        int x, now = 0; scanf("%d", &x);
        for (char c = 'A'; c <= 'E'; c++) { now = std::max(now, get(i, c)); }
        ans += 1ll * x * now;
    }
    printf("%I64d\n", ans);
    return 0;
}