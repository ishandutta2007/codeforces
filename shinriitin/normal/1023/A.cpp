#include <bits/stdc++.h>

const int max_N = (int) 2e5 + 21;

int n, m, pos = -1;

char s[max_N], t[max_N];

int main() {
    scanf("%d%d%s%s", &n, &m, s, t);
    pos = n;
    for (int i = 0; i < n; ++i) if (s[i] == '*') {
        pos = i; break;
    }
    if (pos == n) return puts(strcmp(s, t) ? "NO" : "YES"), 0;
    if (m < n - 1) return puts("NO"), 0;
    for (int i = 0; i < pos; ++i) if (s[i] != t[i]) return puts("NO"), 0;
    for (int i = 0; n - i - 1 > pos ; ++i) if (s[n - i - 1] != t[m - i - 1]) return puts("NO"), 0;
    return puts("YES"), 0;
}