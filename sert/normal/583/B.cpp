#include <cstdio>
const int N = 1e5 + 34;
bool u[N];
int a[N];
int x, dx, k, n, ans;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    x = 0;
    dx = 1;
    while (k < n) {
        if (!u[x] && k >= a[x]) {
            u[x] = true;
            k++;
        }
        if (k == n)
            break;
        if (x == 0 && dx == -1) {
            dx = 1;
            ans++;
        }
        if (x == n - 1 && dx == 1) {
            dx = -1;
            ans++;
        }
        x += dx;
    }
    printf("%d", ans);
}