#include <cstdio>
#include <algorithm>
int n, m, a[4000], fail;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    std::sort(a, a + m);
    for (int i = 1; i < m - 1; i++)
        if (a[i - 1] + 1 == a[i] && a[i] == a[i + 1] - 1)
            fail = 1;
    if (a[0] == 1 || a[m - 1] == n || fail) printf("NO\n");
    else printf("YES\n");
}