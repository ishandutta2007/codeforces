#include <cstdio>
int n, k, a2, a1;
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        if (k == 100) a1++; else a2++;
    }
    if (a1 % 2 == 1 || (a2 % 2 == 1 && a1 < 2)) printf("NO\n"); else printf("YES\n");
}