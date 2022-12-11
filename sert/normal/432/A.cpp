#include <cstdio>
int n, k, x, ans;
int main() {
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d", &x);
        ans += int(x + k < 6);
    }
    printf("%d\n", ans / 3);
}