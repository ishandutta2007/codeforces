#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, q, type, x, y, z;
double p[N];

struct pnt{
    double x, y;
    pnt(double x = -1, double y = -1) : x(x), y(y) {}
    pnt operator+ (const pnt &b) const {
        if (x == -1 && y == -1) return pnt(b.x, b.y);
        if (b.x == -1 && b.y == -1) return pnt(x, y);
        return pnt(x * b.x / (1 + y * (b.x - 1)), b.y + y * b.x * (1 - b.y) / (1 + y * (b.x - 1)));
    }
} ;

pnt add[N<<2];

void push_up(int id) {
    add[id] = add[id<<1] + add[id<<1^1];
    return;
}

void build(int l, int r, int id) {
    if (l == r) {
        add[id] = pnt(p[l], p[l]);
        return;
    }
    int m = l + r >> 1;
    build(l, m, id << 1);
    build(m + 1, r, id << 1 ^ 1);
    push_up(id);
}

void update(int pos, double val, int l, int r, int id) {
    if (pos < l || pos > r) return;
    if (l == r) {
        add[id] = pnt(val, val);
        return;
    }
    int m = l + r >> 1;
    update(pos, val, l, m, id << 1);
    update(pos, val, m + 1, r, id << 1 ^ 1);
    push_up(id);
}

pnt query(int L, int R, int l, int r, int id) {
    if (R < l || r < L) return pnt(-1, -1);
    if (L <= l && r <= R) return add[id];
    int m = l + r >> 1;
    return query(L, R, l, m, id << 1) + query(L, R, m + 1, r, id << 1 ^ 1);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = 1.0 * x / y;
    }
    build(1, n, 1);
    while (q --) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d", &x, &y, &z);
            update(x, 1.0 * y / z, 1, n, 1);
        }
        else {
            scanf("%d %d", &x, &y);
            printf("%.10lf\n", query(x, y, 1, n, 1).x);
        }
    }
}