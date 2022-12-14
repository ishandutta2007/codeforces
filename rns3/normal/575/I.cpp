#include <bits/stdc++.h>

using namespace std;

#define N 100005

struct pnt {
    int x, y, z, id;
    pnt(int x = 0, int y = 0, int z = 0, int id = 0) : x(x), y(y), z(z), id(id) {}
} p[5][N], tmp[N], a[N], b[N];

int n;
int cnt[5], rlt[N];
int bit[15005];

bool cmpx(pnt a, pnt b) { return a.x != b.x ? a.x < b.x : a.id < b.id; }
bool cmpy(pnt a, pnt b) { return a.y != b.y ? a.y < b.y : a.id < b.id; }

void add(int p, int v) {
    for (int i = p; i <= 3 * n; i += i & -i) bit[i] += v;
}

int query(int p) {
    int rlt = 0;
    for (int i = p; i; i -= i & -i) rlt += bit[i];
    return rlt;
}

void calc(int l, int r) {
    if (r <= l) return;
    int tot = 0, mid = l + r >> 1;
    for (int i = l; i <= r; i ++) {
        if (!b[i].id) add(b[i].z, 1), tot ++;
        else rlt[b[i].id] += tot - query(b[i].z - 1);
    }
    for (int i = l; i <= r; i ++) {
        if (!b[i].id) add(b[i].z, -1);
    }
}

void cdq2(int l, int r) {
    if (r <= l) return;
    int mid = l + r >> 1, tot = 0;
    for (int i = l; i <= mid; i ++) if (!a[i].id) b[++ tot] = a[i];
    for (int i = mid + 1; i <= r; i ++) if (a[i].id) b[++ tot] = a[i];
    sort(b + 1, b + tot + 1, cmpy);
    calc(1, tot);
    cdq2(l, mid), cdq2(mid + 1, r);
}

void cdq1(int ps, int l, int r) {
    if (r <= l) return;
    int mid = l + r >> 1, tot = 0;
    for (int i = l; i <= mid; i ++) if (!p[ps][i].id) a[++ tot] = p[ps][i];
    for (int i = mid + 1; i <= r; i ++) if (p[ps][i].id) a[++ tot] = p[ps][i];
    sort(a + 1, a + tot + 1, cmpx);
    cdq2(1, tot);
    cdq1(ps, l, mid), cdq1(ps, mid + 1, r);
}

main() {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int bf, d, x, y, z, xx, yy;
        scanf("%d", &bf);
        if (bf == 1) {
            rlt[i] = -1;
            scanf("%d %d %d %d", &d, &x, &y, &z);
            if (d == 1) xx = x, yy = y;
            else if (d == 2) xx = n + 1 - y, yy = x;
            else if (d == 3) xx = y, yy = n + 1 - x;
            else xx = n + 1 - x, yy = n + 1 - y;
            p[d][++ cnt[d]] = pnt(xx, yy, xx + yy + z);
        } else {
            scanf("%d %d", &x, &y);
            p[1][++ cnt[1]] = pnt(x, y, x + y, i);
            xx = n + 1 - y, yy = x;
            p[2][++ cnt[2]] = pnt(xx, yy, xx + yy, i);
            xx = y, yy = n + 1 - x;
            p[3][++ cnt[3]] = pnt(xx, yy, xx + yy, i);
            xx = n + 1 - x, yy = n + 1 - y;
            p[4][++ cnt[4]] = pnt(xx, yy, xx + yy, i);
        }
    }
    for (int i = 1; i <= 4; i ++) cdq1(i, 1, cnt[i]);
    for (int i = 1; i <= m; i ++) {
        if (rlt[i] >= 0) printf("%d\n", rlt[i]);
    }
}