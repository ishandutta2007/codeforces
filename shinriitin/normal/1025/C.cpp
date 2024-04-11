#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;

int n, cnt, ans;

char s[max_N << 1];

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) s[i + n] = s[i];
    ans = cnt = 1;
    for (int i = 1; i < 2 * n; ++i)
        if (s[i - 1] != s[i]) ans = std::max(ans, ++cnt);
        else cnt = 1;
    printf("%d\n", std::min(n, ans));
    return 0;
}