#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <cstdio>
int n, m, l, r;
unsigned char a[200000], x, y;
int main() {
    scanf("%d", &n);
    for (register int i = 0; i < n; i++) scanf("%hhu", &a[i]);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%hhu%hhu", &l, &r, &x, &y);
        for (l--; l < r; l++)
            if (a[l] == x) a[l] = y;
    }
    for (int i = 0; i < n; i++) printf("%hhu ", a[i]);
    puts("");
    return 0;
}