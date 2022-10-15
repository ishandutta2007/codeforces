#include <bits/stdc++.h>

const int mod = 998244353;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

const int N = 3e3 + 5;

int n, m, ans, f[N][N];
char s[N], t[N];

bool check(int i, int j) {
    return t[j] == '*' ? true : s[i] == t[j];
}

int main() {
    scanf("%s", s); n = strlen(s);
    scanf("%s", t); m = strlen(t);
    for (int i = m; i < n; i++) { t[i] = '*'; }
    for (int i = 0; i < n; i++) { f[i][i] = check(0, i) ? 2 : 0; }
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n; i++) {
            int j = i + len;
            if (j == n) { break; }
            if (check(len, i)) { f[i][j] = add(f[i][j], f[i + 1][j]); }
            if (check(len, j)) { f[i][j] = add(f[i][j], f[i][j - 1]); }
        }
    }
    for (int i = m - 1; i < n; i++) { ans = add(ans, f[0][i]); }
    printf("%d\n", ans);
    return 0;
}