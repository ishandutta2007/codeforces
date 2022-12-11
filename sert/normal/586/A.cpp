#include <cstdio>
const int N = 1e5 + 34;
int n, ans;
int a[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1)
            ans++;
    }
    for (int i = 1; i < n - 1; i++)
        if (a[i] == 0 && a[i - 1] * a[i + 1] == 1)
            ans++;
    printf("%d\n", ans);
}