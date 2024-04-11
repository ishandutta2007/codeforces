#include <bits/stdc++.h>
using namespace std;

struct pnt{
    double x, y;
    pnt(double x = 0, double y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &p) {
        return pnt(x + p.x, y + p.y);
    }
    pnt operator - (const pnt &p) const {
        return pnt(x - p.x, y - p.y);
    }
    pnt operator * (const double &d) {
        return pnt(x * d, y * d);
    }
    pnt operator / (const double &d) {
        return pnt(x / d, y / d);
    }
    double dist() {
        return sqrt(x * x + y * y);
    }
    double operator & (const pnt &p) {
        return x * p.x + y * p.y;
    }
    double operator ^ (const pnt &p) {
        return x * p.y - y * p.x;
    }
    friend double dist(const pnt &a, const pnt &b) {
        return (a - b).dist();
    }
    void in() {
        scanf("%lf %lf", &x, &y);
    }
    void out() {
        printf("%.5lf %.5lf\n", x, y);
    }
    pnt rot() {
        return pnt(-y, x);
    }
} p[3], o[3];

double r[3], o_r[3];

void make(pnt a, pnt b, double x, double y, pnt &p, double &r) {
    pnt c = (a * y + b * x) / (x + y);
    pnt d = (b * x - a * y) / (x - y);
    p = (c + d) / 2, r = dist(c, p);
}

const double ep = 1e-8;

int inter_circle(pnt a, double x, pnt b, double y, pnt *p) {
    double d = dist(a, b);
    if (d > x + y || x > d + y || y > d + x) return 0;
    double al = (x * x - y * y + d * d) / (2 * d);
    pnt cp = (a * (d - al) + b * al) / d;
    if (abs(x + y - d) < ep || abs(d + y - x) < ep || abs(d + x - y) < ep) {
        p[0] = cp; return 1;
    }
    double h = sqrt(x * x - al * al);
    pnt dv = (b - a).rot() * h / d;
    p[0] = cp + dv, p[1] = cp - dv;
    return 2;
}

pnt outercenter(pnt a, pnt b, pnt c) {
    return (a + b + (b - a).rot() * (a - c & b - c) / (a - c ^ b - c)) / 2;
}

int main() {
    for (int i = 0; i < 3; i ++) p[i].in(), scanf("%lf", &r[i]);

    if (abs(r[0] - r[1]) < ep && abs(r[1] - r[2]) < ep) {
        outercenter(p[0], p[1], p[2]).out();
        return 0;
    }
    if (abs(r[0] - r[1]) < ep) swap(r[1], r[2]), swap(p[1], p[2]);
    else if (abs(r[1] - r[2]) < ep) swap(r[0], r[1]), swap(p[0], p[1]);

    for (int i = 0; i < 2; i ++) make(p[i], p[i+1], r[i], r[i+1], o[i], o_r[i]);
    int cnt = inter_circle(o[0], o_r[0], o[1], o_r[1], p + 1);
    if (cnt) {
        if (cnt == 2 && dist(p[2], p[0]) < dist(p[1], p[0])) swap(p[1], p[2]);
        p[1].out();
    }
    return 0;
}