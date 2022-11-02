#include <bits/stdc++.h>

int n, lo, hi, mi, tp;

int check(int x) {
    int a, b;
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &a);
    printf("? %d\n", x + (n >> 1));
    fflush(stdout);
    scanf("%d", &b);
    if (a == b) {
        printf("! %d\n", x);
        exit(0);
    }
    return (a < b) ? -1 : 1;
}

int main() {
    scanf("%d", &n);
    if (n % 4 != 0) return puts("! -1"), 0;
    tp = check(1);
    lo = 1, hi = (n >> 1);
    while (lo <= hi) {
        mi = (lo + hi) >> 1;
        if (check(mi) == tp) lo = mi + 1;
        else hi = mi - 1;
    }
    return puts("! -1"), 0;
}