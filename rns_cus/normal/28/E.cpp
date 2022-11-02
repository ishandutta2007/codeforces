#include <bits/stdc++.h>
using namespace std;

#define N 10100

const double ep = 1e-8;
struct pnt{
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    double operator ^ (const pnt &b) {
        return x * b.y - y * b.x;
    }
    double operator & (const pnt &b) {
        return x * b.x + y * b.y;
    }
    double dist() {
        return sqrt(x * x + y * y);
    }
    pnt operator + (const pnt &b) {
        return pnt(x + b.x, y + b.y);
    }
    pnt operator - (const pnt &b) {
        return pnt(x - b.x, y - b.y);
    }
    pnt operator * (double b) {
        return pnt(x * b, y * b);
    }
    pnt operator / (double b) {
        return pnt(x / b, y / b);
    }
    pnt operator - () {
        return pnt(-x, -y);
    }
    void in() {
        scanf("%lf %lf", &x, &y);
    }
} p[N], A, V, U;

double F, zv, zu;

inline int sgn(double d) {
    return d < -ep ? -1 : d > ep;
}

bool inside(pnt a, pnt b, pnt c) {
    return abs(a - b ^ a - c) < ep && (a - b & a - c) <= 0;
}

int inter_line(pnt a, pnt b, pnt c, pnt d, pnt &rlt) {
    double s = a - b ^ c - d;
    if (abs(s) < ep) return 0;
    double x = (a - d ^ c - d) / s;
    rlt = a * (1 - x) + b * x;
    return 1;
}

int n;

double T1 = 1e9, T2 = 1e9;

inline void update(double t1, double t2) {
    int c = sgn(t1 - T1);
    if (c > 0) return;
    if (c < 0) T1 = t1, T2 = t2;
    else if (t2 < T2) T2 = t2;
}

double d1, d2;

void check(pnt c) {
    int p = sgn(V ^ c - A), q = sgn(c - A ^ V - U), r = sgn(V ^ V - U);
    if (p && p != r) return;
    if (q && q != r) return;
    pnt tmp;
    assert(inter_line(c, c + U, A, A + V - U, tmp) == 1);
    update((tmp - A).dist() / d1, (tmp - c).dist() / d2);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) p[i].in();
    A.in(), V.in(); scanf("%lf", &zv);
    scanf("%lf", &F), U.in(), scanf("%lf", &zu);
    d2 = F * U.dist() / zu;
    U = U * zv / zu;
    d1 = (V - U).dist();
    if (sgn(U ^ V)) {
        for (int i = 0; i < n; i ++) check(p[i]);
        for (int i = 0, j = 1; i < n; i ++, j ++) {
            if (j == n) j = 0;
            pnt tmp;
            if (inter_line(p[i], p[j], A, A + V - U, tmp) && inside(tmp, p[i], p[j])) check(tmp);
            if (inter_line(p[i], p[j], A, A + V, tmp) && inside(tmp, p[i], p[j])) check(tmp);
        }
    }
    else {
        if (sgn(V & U) <= 0) {
            for (int i = 0, j = 1; i < n; i ++, j ++) {
                if (j == n) j = 0;
                pnt tmp;
                if (inter_line(p[i], p[j], A, A + V - U, tmp) && inside(tmp, p[i], p[j])) {
                    if (sgn(tmp - A & V - U) >= 0) update((tmp - A).dist() / d1, 0);
                }
            }
        }
        else {
            int sg = sgn(V.dist() - U.dist());
            if (sg >= 0) {
                for (int i = 0, j = 1; i < n; i ++, j ++) {
                    if (j == n) j = 0;
                    pnt tmp;
                    if (inter_line(p[i], p[j], A, A + V, tmp) && inside(tmp, p[i], p[j])) {
                        if (sgn(tmp - A & V) >= 0) {
                            double t = (tmp - A).dist() / V.dist();
                            update(t, (tmp - A - (V - U) * t).dist() / d2);
                        }
                    }
                }
            }
            else if (sg < 0) {
                for (int i = 0, j = 1; i < n; i ++, j ++) {
                    if (j == n) j = 0;
                    pnt tmp;
                    if (inter_line(p[i], p[j], A, A + V, tmp) && inside(tmp, p[i], p[j])) {
                        if (sgn(tmp - A & V) >= 0) {
                            double t = (tmp - A).dist() / V.dist();
                            update(t, (tmp - A - (V - U) * t).dist() / d2);
                        }
                        else update((tmp - A).dist() / d1, 0);
                    }
                }
            }
        }
    }
    if (T1 > 1e6) puts("-1 -1");
    else printf("%.8lf %.8lf\n", T1, T2);

    return 0;
}