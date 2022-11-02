#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, k, a[N], b[N], c[N], d[N], x[N];
int f_st, f_ed;

const int mod = 998244353;

int func(int m) {
    if (!f_st || !f_ed) {
        if (!f_st && !f_ed) return a[m];
        else return b[m];
    }
    if (f_st == f_ed) return c[m];
    else return d[m];
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", &x[i]);
    b[1] = k - 1;
    for (int i = 2; i < n; i ++) b[i] = 1ll * (k - 1) * b[i-1] % mod;
    a[1] = k;
    for (int i = 2; i < n; i ++) a[i] = 1ll * k * b[i-1] % mod;
    d[1] = k - 2, d[2] = (1ll * (k - 2) * (k - 2) + k - 1) % mod;
    for (int i = 3; i < n; i ++) d[i] = (1ll * (k - 2) * d[i-1] + 1ll * (k - 1) * d[i-2]) % mod;
    c[1] = k - 1;
    for (int i = 2; i < n; i ++) c[i] = 1ll * (k - 1) * d[i-1] % mod;
    int rlt = 1;
    for (int i = 0; i < n; ) {
        f_st = f_ed = 0;
        while (i < n && x[i] != -1) {
            if (x[i] == x[i+2]) rlt = 0;
            i += 2;
        }
        if (i >= n) break;
        int j = i;
        if (j > 0) f_st = x[j-2];
        while (i < n && x[i] == -1) i += 2;
        if (i < n) f_ed = x[i];
        rlt = 1ll * rlt * func((i - j) / 2) % mod;
    }
    for (int i = 1; i < n; ) {
        f_st = f_ed = 0;
        while (i < n && x[i] != -1) {
            if (x[i] == x[i+2]) rlt = 0;
            i += 2;
        }
        if (i >= n) break;
        int j = i;
        if (j > 1) f_st = x[j-2];
        while (i < n && x[i] == -1) i += 2;
        if (i < n) f_ed = x[i];
        rlt = 1ll * rlt * func((i - j) / 2) % mod;
    }
    printf("%d\n", rlt);
}