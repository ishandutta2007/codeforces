#include <cstdio>
int n, k, a[200], a2, a1, ans;
int main() {
    //freopen("a.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < k; i++) {
        a2 = a1 = 0;
        for (int j = i; j < n; j += k)
            if (a[j] == 1) a1++; else a2++;
        ans += (a1 < a2 ? a1 : a2);
    }
    printf("%d\n", ans);
}