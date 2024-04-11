#include <bits/stdc++.h>
using namespace std;

#define N 505

int n;
char s[10], rlt[N<<1];

bool query(int r1, int c1, int r2, int c2) {
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    scanf("%s", s);
    return s[0] == 'Y';
}

int main() {
    scanf("%d", &n);
    int r = 1, c = 1, p = 0;
    while (r + c <= n) {
        if (query(r + 1, c, n, n)) r ++, rlt[p++] = 'D';
        else c ++, rlt[p++] = 'R';
    }
    r = n, c = n, p = 2 * n - 2;
    while (r + c > n + 1) {
        if (query(1, 1, r, c - 1)) c --, rlt[--p] = 'R';
        else r --, rlt[--p] = 'D';
    }
    printf("! %s\n", rlt);

    return 0;
}