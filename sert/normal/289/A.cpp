#include <cstdio>
int n, k, l, r, sum, ans;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        sum = (sum + r - l + 1) % k;
    }
    ans = (k - sum) % k;
    printf("%d\n", ans);
}