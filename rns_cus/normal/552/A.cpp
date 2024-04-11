#include <cstdio>

int ans;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0, x, y, xx, yy; i < n; i ++) {
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        ans += (xx - x + 1) * (yy - y + 1);
    }
    printf("%d\n", ans);
}