#include <cstdio>
#include <algorithm>
int n, a[201], kol, ans, sum;
bool u[201];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    std::sort(a, a + n);
    while (kol < n) {
        ans++;
        sum = 0;
        for (int i = 0; i < n; i++)
            if (!u[i] && a[i] >= sum) {
                u[i] = true;
                sum++;
                kol++;
            }
    }
    printf("%d\n", ans);
}