#include <cstdio>
int n, x, y, xx, yy, a[1000];
char s[123456];
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d%d%d%d%d ", &n, &x, &y, &xx, &yy);
    if (x < xx) a['E'] = xx - x; else a['W'] = x - xx;
    if (y < yy) a['N'] = yy - y; else a['S'] = y - yy;
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (a[s[i]]) a[s[i]]--;
        if (!a['S'] && !a['N'] && !a['E'] && !a['W']) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
}