#include <cstdio>
#define min(a, b) (a < b ? a : b)
int n, mn1, mn2, mx1, mx2, a[1111];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++)
    for (int j = i + 2; j < n - 1; j++) {
        mn1 = min(a[i], a[i + 1]);
        mn2 = min(a[j], a[j + 1]);
        mx1 = a[i] + a[i + 1] - min(a[i], a[i + 1]);
        mx2 = a[j] + a[j + 1] - min(a[j], a[j + 1]);
        if (mn1 <= mn2 && mn2 <= mx1 && mx1 <= mx2) {printf("yes\n"); return 0;}
        if (mn2 <= mn1 && mn1 <= mx2 && mx2 <= mx1) {printf("yes\n"); return 0;}
    }
    printf("no\n");
}