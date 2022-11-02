#include <bits/stdc++.h>

const int max_N = (int) 2e5 + 21;

int n, q, l[max_N], r[max_N], a[max_N];

int b[max_N], f[max_N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void dye(int l, int r, int c) {
    int x = find(l);
    while (x <= r) {
        b[x] = c;
        f[x] = x + 1;
        x = find(x);
    }
}

void redye(int x) {
    if (b[x]) return;
    redye(x + 1);
    b[x] = b[x + 1];
}

int main() {
    scanf("%d%d", &n, &q);
    bool allZero = true;
    for (int i = 1; i <= n; ++i) {
        f[i] = i;
        scanf("%d", a + i);
        if (!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
        if (a[i]) allZero = false;
    }
    if (allZero) {
        puts("YES");
        for (int i = 1; i <= n; ++i) printf("%d%c", q, " \n"[i == n]);
        return 0;
    }
    f[n + 1] = n + 1;
    for (int i = q; i; --i) {
        if (!l[i]) continue;
        dye(l[i], r[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        redye(i);
        for (int j = i + 1; j <= n && !b[j]; ++j) b[j] = b[i];
        if (a[i] && a[i] != b[i]) return puts("NO"), 0;
    }
    if (!l[q]) {
        bool ok = false;
        for (int i = 1; i <= n; ++i) {
            if (!a[i]) {
                ok = true;
                b[i] = q;
                break;
            }
        }
        if (!ok) return puts("NO"), 0;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
    return 0;
}