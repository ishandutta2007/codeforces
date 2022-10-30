#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, mod, cnt, pp[15], tmp[15], a[N], sum[N<<2], mul[N<<2][15];
bool addv[N<<2];

int powmod(int a, int n) {
    int rlt = 1;
    while (n) {
        if (n & 1) rlt = 1ll * rlt * a % mod;
        a = 1ll * a * a % mod, n >>= 1;
    }
    return rlt;
}

void prepare() {
    int p = mod;
    for (int i = 2; i * i <= p; i ++) {
        if (p % i == 0) {
            pp[++cnt] = i;
            while (p % i == 0) p /= i;
        }
    }
    if (p > 1) pp[++cnt] = p;
}

void split(int x) {
    tmp[cnt+1] = x % mod;
    for (int i = 1; i <= cnt; i ++) {
        tmp[i] = 0;
        while (x % pp[i] == 0) x /= pp[i], tmp[i] ++;
    }
    tmp[0] = x % mod;
}

void add(int *x, int *y) {
    x[0] = 1ll * x[0] * y[0] % mod;
    x[cnt+1] = 1ll * x[cnt+1] * y[cnt+1] % mod;
    for (int i = 1; i <= cnt; i ++) x[i] += y[i];
}

int extended_euclid(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int rlt = extended_euclid(b, a % b, x, y);
    int z = x;
    x = y, y = z - a / b * y;
    return rlt;
}

int invmod(int x) {
    int a, b;
    extended_euclid(x, mod, a, b);
    if (a < 0) a += mod;
    return a;
}

#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)

void push_down(int v) {
    if (addv[v]) {
        add(mul[le], mul[v]);
        add(mul[ri], mul[v]);
        sum[le] = 1ll * sum[le] * mul[v][cnt+1] % mod;
        sum[ri] = 1ll * sum[ri] * mul[v][cnt+1] % mod;
        memset(mul[v] + 1, 0, 4 * cnt);
        mul[v][0] = mul[v][cnt+1] = 1;
        addv[v] = 0, addv[le] = addv[ri] = 1;
    }
}

void push_up(int v) {
    sum[v] = sum[le] + sum[ri];
    if (sum[v] >= mod) sum[v] -= mod;
}

void build(int v, int vl, int vr) {
    mul[v][0] = mul[v][cnt+1] = 1;
    if (vl == vr) {
        sum[v] = a[vl] % mod;
        return;
    }
    build(le, vl, mi), build(ri, mi + 1, vr);
    push_up(v);
}

void multiply(int v, int vl, int vr, int l, int r) {
    if (vl > r || l > vr) return;
    if (l <= vl && vr <= r) addv[v] = 1, add(mul[v], tmp), sum[v] = 1ll * sum[v] * tmp[cnt+1] % mod;
    else {
        push_down(v);
        multiply(le, vl, mi, l, r), multiply(ri, mi + 1, vr, l, r);
        push_up(v);
    }
}

int query(int v, int vl, int vr, int l, int r) {
    if (vl > r || l > vr) return 0;
    if (l <= vl && vr <= r) return sum[v];
    push_down(v);
    int rlt = query(le, vl, mi, l, r) + query(ri, mi + 1, vr, l, r);
    if (rlt >= mod) rlt -= mod; return rlt;
}

void divide(int v, int vl, int vr, int p) {
    if (vl == vr) {
        int *x = mul[v];
        x[0] = 1ll * x[0] * invmod(tmp[0]) % mod;
        x[cnt+1] = x[0];
        for (int i = 1; i <= cnt; i ++) {
            x[i] -= tmp[i];
            while (x[i] < 0) a[p] /= pp[i], x[i] ++;
            x[cnt+1] = 1ll * x[cnt+1] * powmod(pp[i], x[i]) % mod;
        }
        sum[v] = 1ll * a[p] * x[cnt+1] % mod;
        return;
    }
    push_down(v);
    if (p <= mi) divide(le, vl, mi, p);
    else divide(ri, mi + 1, vr, p);
    push_up(v);
}

int main() {
    scanf("%d %d", &n, &mod);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    prepare(), build(1, 1, n);
    int q; scanf("%d", &q);
    while (q --) {
        int ty;
        scanf("%d", &ty);
        if (ty == 1) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            split(x), multiply(1, 1, n, l, r);
        }
        else if (ty == 2) {
            int p, x;
            scanf("%d %d", &p, &x);
            split(x), divide(1, 1, n, p);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}