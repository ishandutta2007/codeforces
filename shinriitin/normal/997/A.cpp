#include <bits/stdc++.h>

const int max_N = (int) 3e5 + 21;

int n, x, y, cnt;

char s[max_N];

int main() {
    scanf("%d%d%d%s", &n, &x, &y, s);
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1] && s[i - 1] == '0') {
            ++cnt;
        }
    }
    if (s[n - 1] == '0')++cnt;
    if (!cnt)puts("0");
    else {
        long long ans = 1ll * cnt * y;
        ans = std::min(ans, 1ll * (cnt - 1) * x + y);
        printf("%lld\n", ans);
    }
    return 0;
}