#include <bits/stdc++.h>

const int max_N = (int) 3e5 + 21;

int n, c[max_N], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", c + i);
    }
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[1]) continue;
        ans = std::max(ans, i - 1);
    }
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[1]) continue;
        for (int j = i + 1; j <= n; ++j) {
            if (c[i] == c[j]) continue;
            ans = std::max(ans, j - i);
        }
        break;
    }
    printf("%d\n", ans);
}