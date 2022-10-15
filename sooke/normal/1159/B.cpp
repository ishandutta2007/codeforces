#include <cstdio>
#include <algorithm>

const int N = 300005;

int n, l, r, ans = 1e9;
std::pair<int, int> a[N];

int main() {
    scanf("%d", &n); l = n + 1;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x); a[i] = {x, i};
    }
    std::sort(a + 1, a + n + 1);
    for (int i = n, x, u; i; i--) {
        x = a[i].first; u = a[i].second;
        l = std::min(l, u); r = std::max(r, u);
        if (u != l) { ans = std::min(ans, x / (u - l)); }
        if (u != r) { ans = std::min(ans, x / (r - u)); }
    }
    printf("%d\n", ans);
    return 0;
}