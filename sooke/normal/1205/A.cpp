#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, a[N];

int main() {
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("NO\n"); return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            a[i] = i << 1; a[i + n] = i << 1 | 1;
        } else {
            a[i] = i << 1 | 1; a[i + n] = i << 1;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n + n; i++) {
        printf("%d ", a[i] + 1);
    }
    return 0;
}