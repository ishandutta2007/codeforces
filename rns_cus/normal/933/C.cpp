#include <bits/stdc++.h>
using namespace std;

#define N 20

const double ep = 1e-8;
struct pnt {
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &b) {
        return pnt(x + b.x, y + b.y);
    }
    pnt operator - (const pnt &b) {
        return pnt(x - b.x, y - b.y);
    }
    pnt operator * (const double &b) {
        return pnt(x * b, y * b);
    }
    pnt operator / (const double &b) {
        return pnt(x / b, y / b);
    }
    bool operator == (const pnt &b) {
        return abs(x - b.x) < ep && abs(y - b.y) < ep;
    }
    pnt rot() {
        return pnt(-y, x);
    }
    void in() {
        scanf("%lf %lf", &x, &y);
    }
    double dist() {
        return sqrt(x * x + y * y);
    }
} p[N], rlt[N], tmp[N];

int n, r[N], cnt;

int calc(pnt c1, double r1, pnt c2, double r2, pnt *rlt) {
    double d = (c1 - c2).dist();
    if (r1 + r2 < d || r1 + d < r2 || r2 + d < r1) return 0;
    double x = (r1 * r1 - r2 * r2 + d * d) / (d * 2);
    pnt cp = (c1 * (d - x) + c2 * x) / d;
    if (r1 + r2 == d || r1 + d == r2 || r2 + d == r1) {
        rlt[0] = cp;
        return 1;
    }
    double h = sqrt(r1 * r1 - x * x);
    pnt dv = (c2 - c1).rot() * h / d;
    rlt[0] = cp - dv, rlt[1] = cp + dv;
    return 2;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        p[i].in();
        scanf("%d", &r[i]);
    }
    int fi = 0, tp, ans = 0;
    for (int i = 0; i < n; i ++) {
        tp = 0;
        for (int j = 0; j < n; j ++) {
            if (i == j) continue;
            int t = calc(p[i], r[i], p[j], r[j], rlt + cnt);
            for (int x = 0; x < t; x ++) {
                bool fg = 1;
                for (int i = 0; i < tp; i ++)
                    if (tmp[i] == rlt[cnt+x]) fg = 0;
                if (fg) tmp[tp++] = rlt[cnt+x];
            }
            cnt += t;
            if (t > 0) fi ++;
        }
        ans += tp;
    }
    assert(fi % 2 == 0);
    int k = 0;
    for (int i = 0; i < cnt; i ++) {
        bool fg = 1;
        for (int j = 0; j < k; j ++) {
            if (rlt[i] == rlt[j]) fg = 0;
        }
        if (fg) rlt[k++] = rlt[i];
    }
    ans += 2 - k;
    if (fi == 0) ans += (n - 1);
    else if (fi == 2 && n == 3) ans ++;
    printf("%d\n", ans);
}