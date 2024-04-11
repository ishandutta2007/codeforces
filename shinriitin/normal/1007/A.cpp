#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;

int n, a[max_N], cnt, ans;

std::unordered_map<int, int> map;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        ++map[a[i]];
    }
    std::sort(a + 1, a + 1 + n);
    n = std::unique(a + 1, a + 1 + n) - a - 1;
    for (int i = 1; i <= n; ++i) {
        int tmp = std::min(cnt, map[a[i]]);
        cnt -= tmp;
        ans += tmp;
        cnt += map[a[i]];
    }
    printf("%d\n", ans);
    return 0;
}