#include <bits/stdc++.h>
using namespace std;

#define N 100100

int h[N], f[N];

void prepare(char *p) {
    int m = strlen(p);
    h[0] = 0;
    for (int i = 1, j = 0; i < m; i ++) {
        while (j && p[i] != p[j]) j = h[j-1];
        if (p[i] == p[j]) j ++;
        h[i] = j;
    }
}

int kmp(char *t, char *p, bool MN) {
    int n = strlen(t), m = strlen(p);
    for (int i = 0, j = 0; i < n; i ++) {
        while (j && t[i] != p[j]) j = h[j-1];
        if (t[i] == p[j]) j ++;
        f[i] = j;
    }
    if (MN) {for (int i = 0; i < n; i ++) if (f[i] == m) return i;}
    else for (int i = n - 1; ~i; i --) if (f[i] == m) return i - m;
    return -1;
}

char s[N], a[N], b[N];

int main() {
    scanf("%s %s %s", s, a, b);
    prepare(a);
    int x = kmp(s, a, 1);
    prepare(b);
    int y = kmp(s, b, 0);
    bool st = 0, ed = 0;
    if (x >= 0 && y >= x) st = 1;
    reverse(s, s + strlen(s));
    prepare(a);
    x = kmp(s, a, 1);
    prepare(b);
    y = kmp(s, b, 0);
    if (x >= 0 && y >= x) ed = 1;
    x = (st << 1) ^ ed;
    if (x == 0) puts("fantasy");
    else if (x == 1) puts("backward");
    else if (x == 2) puts("forward");
    else puts("both");

    return 0;
}