#include <bits/stdc++.h>
using namespace std;

#define N 200200

const double ep = 1e-12, tpi = 2 * acos(-1);

struct seg{
    double l, r;
    seg(double l = 0, double r = 0) : l(l), r(r) {}
    bool operator < (const seg &s) const {
        if (abs(l - s.l) > ep) return l < s.l;
        return r > s.r;
    }
} s[N];

bool cmp(int x, int y) {
    return s[x] < s[y];
}
#define K 20
int n, m, tot, x[N], y[N], id[N], fa[N][K];
double dis[N];
bool del[N];

bool check(double r) {
    tot = n << 1;
    for (int i = 0; i < n; i ++) {
        double cen = atan2(y[i], x[i]), del = acos(r / dis[i]);
        s[i] = seg(cen - del, cen + del);
    }
    for (int i = n; i < 2 * n; i ++) {
        s[i] = s[i-n];
        s[i].l += tpi;
        s[i].r += tpi;
    }
    for (int i = 0; i < tot; i ++) id[i] = i;
    for (int i = 0; i < n; i ++) del[i] = 0;
    sort(id, id + tot, cmp);
    double mn = 1e7;
    for (int i = tot - 1; ~i; i --) {
        if (s[id[i]].r >= mn) del[id[i]<n?id[i]:id[i]-n] = 1;
        else mn = s[id[i]].r;
    }
    tot = 0;
    for (int i = 0; i < n; i ++) if (!del[i]) s[tot++] = s[i];
    sort(s, s + tot);
    for (int i = tot; i < tot << 1; i ++) {
        s[i] = s[i-tot];
        s[i].l += tpi;
        s[i].r += tpi;
    }
    if (m >= tot) return 1;
    tot <<= 1;
    for (int i = 0, j = 0; i < tot; i ++) {
        while (j < tot && s[j].l < s[i].r + ep) j ++;
        fa[i][0] = j;
    }
    fa[tot][0] = tot;
    for (int k = 1; (1 << k) <= tot; k ++) {
        for (int i = 0; i <= tot; i ++) {
            fa[i][k] = fa[fa[i][k-1]][k-1];
        }
    }
    for (int i = 0; i < tot >> 1; i ++) {
        int p = i;
        for (int k = __lg(m); k >= 0; k --) if (m >> k & 1) p = fa[p][k];
        if (p >= i + (tot >> 1)) return 1;
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    double mn = 1e7;
    for (int i = 0; i < n; i ++) scanf("%d %d", &x[i], &y[i]), dis[i] = sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]), mn = min(mn, dis[i]);
    if (m >= n) {
        printf("%.8lf\n", mn);
        return 0;
    }
    double le = 0, ri = mn;
    while (le < ri - 1e-8) {
        double mi = (le + ri) / 2;
        if (check(mi)) le = mi;
        else ri = mi;
    }
    printf("%.8lf\n", le);

    return 0;
}