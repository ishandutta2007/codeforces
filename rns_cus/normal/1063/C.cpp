#include <bits/stdc++.h>
using namespace std;

#define K 30

char c, s[10];

int main() {
    int n;
    scanf("%d", &n);
    printf("%d %d\n", 0, 0);
    fflush(stdout);
    scanf("%s", s);
    c = s[0];
    n --;
    int h = 0;
    while (n) {
        int m = 1 << n - 1;
        printf("%d %d\n", 0, h + m);
        fflush(stdout);
        scanf("%s", s);
        if (s[0] != c) break;
        h += m, n --;
    }
    if (!n) {
        printf("%d %d %d %d\n", 0, h + 1, 1, h + 1);
        fflush(stdout);
    }
    else {
        int l = h, r = h + (1 << n - 1);
        while (l < r - 1) {
            int mi = l + r >> 1;
            printf("%d %d\n", 0, mi);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == c) l = mi;
            else r = mi;
        }
        printf("%d %d %d %d\n", 1, r, 3, r + 1);
        fflush(stdout);
    }
}