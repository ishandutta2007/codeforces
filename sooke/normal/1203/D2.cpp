#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, m, ans, pre[N], suf[N];
char s[N], t[N];

int main() {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1); m = strlen(t + 1);
    pre[0] = 0; suf[m + 1] = n + 1;
    for (int i = 1, j = 1; i <= n && j <= m; i++) {
        if (s[i] == t[j]) { pre[j++] = i; }
    }
    for (int i = n, j = m; i >= 1 && j >= 1; i--) {
        if (s[i] == t[j]) { suf[j--] = i; }
    }
    for (int i = 1; i <= m + 1; i++) {
        ans = std::max(ans, suf[i] - pre[i - 1]);
    } printf("%d\n", ans - 1);
    return 0;
}