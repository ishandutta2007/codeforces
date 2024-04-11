#include <bits/stdc++.h>
using namespace std;

#define N 100100

struct pnt{
    int pos[2], id;
    void in(int i) {scanf("%d %d", &pos[0], &pos[1]), id = i;}
} p[N];

int now;

bool cmp(int a, int b) {return p[a].pos[now] < p[b].pos[now];}

struct target{
    int lx, rx, ly, ry, z, id;
    void in(int i) {scanf("%d %d %d %d %d", &lx, &rx, &ly, &ry, &z), id = i;}
    bool operator < (const target &t) const {
        return z < t.z;
    }
} q[N];

struct node{
    int lx, rx, ly, ry, fa, l, r, id;
} t[N];

#define le t[v].l
#define ri t[v].r

inline void chkmin(int &x, int y) {
    if (x > y) x = y;
}

inline void chkmax(int &x, int y) {
    if (x < y) x = y;
}

void update(int v) {
    if (le) {
        chkmin(t[v].lx, t[le].lx);
        chkmin(t[v].ly, t[le].ly);
        chkmax(t[v].rx, t[le].rx);
        chkmax(t[v].ry, t[le].ry);
        chkmin(t[v].id, t[le].id);
    }
    if (ri) {
        chkmin(t[v].lx, t[ri].lx);
        chkmin(t[v].ly, t[ri].ly);
        chkmax(t[v].rx, t[ri].rx);
        chkmax(t[v].ry, t[ri].ry);
        chkmin(t[v].id, t[ri].id);
    }
}

int id[N];

int build(int l, int r, int axis) {
    if (l > r) return 0;
    int m = l + r >> 1;
    now = axis;
    nth_element(id + l, id + m, id + r + 1, cmp);
    int v = id[m];
    le = build(l, m - 1, axis ^ 1);
    ri = build(m + 1, r, axis ^ 1);
    if (le) t[le].fa = v;
    if (ri) t[ri].fa = v;
    t[v].lx = t[v].rx = p[v].pos[0];
    t[v].ly = t[v].ry = p[v].pos[1];
    t[v].id = p[v].id;
    update(v);
    return v;
}

int n, m, cur, lx, ly, rx, ry, ans[N];

void query(int v) {
    if (!v || cur <= t[v].id || rx < t[v].lx || t[v].rx < lx || ry < t[v].ly || t[v].ry < ly) return;
    if (lx <= t[v].lx && t[v].rx <= rx && ly <= t[v].ly && t[v].ry <= ry) return chkmin(cur, t[v].id), void();
    if (lx <= p[v].pos[0] && p[v].pos[0] <= rx && ly <= p[v].pos[1] && p[v].pos[1] <= ry) chkmin(cur, p[v].id);
    bool fg = 0;
    if (t[le].id < t[ri].id) fg = 1;
    if (fg) query(le);
    query(ri);
    if (!fg) query(le);
}

const int inf = 1e9;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) q[i].in(i);
    sort(q + 1, q + n + 1);
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) p[i].in(i), id[i] = i;
    int rt = build(1, m, 0);
    for (int i = 1; i <= n; i ++) {
        lx = q[i].lx, rx = q[i].rx;
        ly = q[i].ly, ry = q[i].ry;
        cur = m + 1;
        query(rt);
        if (cur <= m) {
            ans[cur] = q[i].id;
            p[cur].id = m + 1;
            for (; cur; cur = t[cur].fa) {
                if (p[cur].id > m) t[cur].lx = t[cur].ly = inf, t[cur].rx = t[cur].ry = -inf;
                else t[cur].lx = t[cur].rx = p[cur].pos[0], t[cur].ly = t[cur].ry = p[cur].pos[1];
                t[cur].id = p[cur].id;
                update(cur);
            }
        }
    }
    for (int i = 1; i <= m; i ++) printf("%d\n", ans[i]);

    return 0;
}