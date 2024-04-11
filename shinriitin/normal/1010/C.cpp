#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;

int n, k, g, a[max_N], ans;

bool vis[max_N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        g = std::__gcd(g, a[i]);
    }
    g %= k;
    int x = g;
    while (!vis[x]) {
        vis[x] = true;
        ++ans;
        x = (x + g) % k;
    }
    printf("%d\n", ans);
    for (int i = 0; i < k; ++i) {
        if (!vis[i]) continue;
        printf("%d ", i);
    }
    return 0;
}