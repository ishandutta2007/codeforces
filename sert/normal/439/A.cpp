#include <cstdio>
int n, d, t, sum = -10, ans;
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        sum += t + 10;
    }
    ans = (sum > d ? -1 : (n - 1) * 2 + (d - sum) / 5);
    printf("%d\n", ans);
}