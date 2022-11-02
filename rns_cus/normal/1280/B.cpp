#include <bits/stdc++.h>
using namespace std;

#define N 111

int a[N], b[N];
char s[N][N];
int r, c;

int solve() {

    for (int i = 1; i <= r; i ++) a[i] = 0;
    for (int i = 1; i <= c; i ++) b[i] = 0;
    for (int i = 1; i <= r; i ++) for (int j = 1; j <= c; j ++) if (s[i][j] == 'A') a[i] ++, b[j] ++;

    bool fg = 0;
    for (int i = 1; i <= r; i ++) if (a[i]) fg = 1;
    if (!fg) return -1;
    fg = 0;
    for (int i = 1; i <= r; i ++) if (a[i] < c) fg = 1;
    if (!fg) return 0;
    if (a[1] == c || a[r] == c || b[1] == r || b[c] == r) return 1;
    if (s[1][1] == 'A' || s[1][c] == 'A' || s[r][1] == 'A' || s[r][c] == 'A') return 2;
    for (int i = 1; i <= r; i ++) if (a[i] == c) return 2;
    for (int j = 1; j <= c; j ++) if (b[j] == r) return 2;
    if (a[1] || a[r] || b[1] || b[c]) return 3;
    return 4;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= r; i ++) scanf("%s", s[i] + 1);
        int c = solve();
        if (c < 0) puts("MORTAL");
        else printf("%d\n", c);
    }

    return 0;
}