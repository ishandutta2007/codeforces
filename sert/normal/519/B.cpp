#include <cstdio>
#include <algorithm>
int n, a[100500], b[100500], c[100500];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    std::sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &b[i]);
    std::sort(b, b + n - 1);
    for (int i = 0; i < n - 2; i++)
        scanf("%d", &c[i]);
    std::sort(c, c + n - 2);
    for (int i = 0; true; i++) if (a[i] != b[i]) {printf("%d\n", a[i]); break;}
    for (int i = 0; true; i++) if (c[i] != b[i]) {printf("%d\n", b[i]); break;}
    return 0;
}