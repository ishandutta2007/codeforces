#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 100500
#define maxm 2005

int a[maxn];
int sp[maxm];
int f[maxn], l[maxn];
int n, m;
int ns[2 * maxn];
int ps[2 * maxn];
int used[2 * maxn];
int lp[maxn];
int rp[maxn];

int
main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", sp + i);
        used[sp[i]] = true;
        ns[sp[i]] = sp[i];
        ps[sp[i]] = sp[i];
    }
    for (int i = n; i >= 1; --i) {
        if (i != n && a[i] == a[i + 1] - 1) {
            rp[i] = rp[i + 1];
        } else {
            rp[i] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != 1 && a[i] == a[i - 1] + 1) {
            lp[i] = lp[i - 1];
        } else {
            lp[i] = i;
        }
    }
    for (int i = 2 * maxn - 2; i >= 0; --i) {
        if (ns[i] == 0) {
            ns[i] = ns[i + 1];
        }
    }
    for (int i = 1; i < 2 * maxn; ++i) {
        if (ps[i] == 0) {
            ps[i] = ps[i - 1];
        }
    }
    sort(sp + 1, sp + m + 1);
    f[0] = 0, l[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int df = a[i] - i;
        for (int cp = a[i], cnt = used[a[i]]; cp && df < cp; ++cnt, cp = ps[cp - 1]) {
            l[i] = max(l[i], f[lp[i - a[i] + cp] - 1] + cnt); 
        }
        f[i] = max(f[i], l[i]);
        df = n - i + a[i];
        for (int cp = a[i], cnt = used[a[i]]; cp && df >= cp; ++cnt, cp = ns[cp + 1]) {
            f[rp[i + cp - a[i]]] = max(f[rp[i + cp - a[i]]], l[i] + cnt - used[a[i]]);
        }
    }
    int res = *max_element(f + 1, f + n + 1);
    printf("%d\n", res);
    return 0;
}