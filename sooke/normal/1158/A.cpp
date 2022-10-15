#include <cstdio>
#include <algorithm>

const int N = 100005;

int n, m, a[N], b[N];
long long sa, sb, ans;

bool cmp(int x, int y) { return x > y; }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); sa += a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]); sb += b[i];
    }
    std::sort(a + 1, a + n + 1, cmp);
    std::sort(b + 1, b + m + 1);
    if (a[1] > b[1]) { ans = -1; } else {
        ans = sa * m + sb - a[1] * (m - 1ll);
        ans -= a[1] == b[1] ? a[1] : a[2];
    }
    printf("%I64d\n", ans);
    return 0;
} //