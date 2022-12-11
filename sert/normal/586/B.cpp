#include <cstdio>
#include <algorithm>
const int N = 1e2 + 34;
int a[2][N], b[N], c[N], n;
int getway(int x) {
    int ans = b[x];
    for (int i = 0; i < x; i++)
        ans += a[0][i];
    for (int i = x; i < n - 1; i++)
        ans += a[1][i];
    return ans;
}
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n - 1; i++)
            scanf("%d", a[j] + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    for (int i = 0; i < n; i++)
        c[i] = getway(i);
    std::sort(c, c + n);
    printf("%d\n", c[0] + c[1]);
}