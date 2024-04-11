#include <bits/stdc++.h>
using namespace std;

#define N 600200

int n, a[N], c[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i+n]);
    for (int i = 1; i <= 2 * n; i ++) if (a[i]) c[a[i]] = i;
    int k = c[1];
    if (k <= n) {
        int t = 0;
        for (int i = 1; i <= n; i ++) t = max(t, c[i] - (n + i - 1));
        printf("%d\n", t + n);
    }
    else {
        bool fg = 1;
        for (int i = k; i <= 2 * n; i ++) if (a[i] != i - k + 1) fg = 0;
        if (fg) {
            fg = 1;
            for (int i = 2 * n - k + 2; i <= n; i ++) if (c[i] >= i + k - 1 - n) fg = 0;
            if (fg) return printf("%d\n", k - n - 1), 0;
        }
        int t = 0;
        for (int i = 1; i <= n; i ++) t = max(t, c[i] - (n + i - 1));
        printf("%d\n", t + n);
    }

    return 0;
}