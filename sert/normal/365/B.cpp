#include <cstdio>
int n, a[110000], ans, kol = 2;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    if (n < 3) {printf("%d\n", n); return 0;}
    for (int i = 2; i < n; i++)
        if (a[i] == a[i - 1] + a[i - 2]) kol++;
        else {
            if (kol > ans) ans = kol;
            kol = 2;
        }
    printf("%d\n", (kol > ans ? kol : ans));
}