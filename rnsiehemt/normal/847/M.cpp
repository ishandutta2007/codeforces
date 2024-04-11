#include <bits/stdc++.h>

int n, a[105];

int main() {
    scanf("%d", &n);
    bool ar = true;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        if (i > 1 && a[i] - a[i-1] != a[1] - a[0]) {
            ar = false;
        }
    }
    if (ar) printf("%d\n", a[n-1] + a[1] - a[0]);
    else printf("%d\n", a[n-1]);
}