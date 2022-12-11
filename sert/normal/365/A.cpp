#include <cstdio>
int n, k, x, ans;
bool u[11];
int main() {
    scanf("%d%d", &n, &k);
    while (n--) {
        scanf("%d", &x);
        for (int i = 0; i <= k; i++) u[i] = false;
        while (x > 0) {
            u[x % 10] = true;
            x /= 10;
        }
        for (int i = 0; i <= k; i++)
            if (!u[i]) u[0] = false;
        ans += int(u[0]);
    }
    printf("%d\n", ans);
}