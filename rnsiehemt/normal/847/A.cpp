#include <bits/stdc++.h>

const int maxn = 105;

int n, l[maxn], r[maxn];

int go(int i) {
    while (r[i]) {
        i = r[i];
    }
    return i;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", l+i, r+i);
    }
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] == 0) {
            if (prev) {
                l[i] = prev;
                r[prev] = i;
            }
            prev = go(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", l[i], r[i]);
    }
}