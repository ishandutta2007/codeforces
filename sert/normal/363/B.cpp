#include <cstdio>
int a[1234567], n, k, sum, mx = -1, ps = 1;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < k; i++) sum += a[i];
    mx = sum;
    for (int i = 0; i < n - k; i++) {
        sum = sum + a[i + k] - a[i];
        if (sum < mx) {
            mx = sum;
            ps = i + 2;
        }
    }
    printf("%d\n", ps);
}