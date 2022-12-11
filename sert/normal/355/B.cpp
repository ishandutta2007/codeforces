#include <cstdio>
int n, m, s1, s2, c1, c2, c3, c4, x;
int main() {
    scanf("%d%d%d%d%d%d", &c1, &c2, &c3, &c4, &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s1 += (c1 * x < c2 ? c1 * x : c2);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        s2 += (c1 * x < c2 ? c1 * x : c2);
    }
    s1 = (s1 < c3 ? s1 : c3);
    s2 = (s2 < c3 ? s2 : c3);
    printf("%d\n", (s1 + s2 < c4 ? s1 + s2 : c4));
}