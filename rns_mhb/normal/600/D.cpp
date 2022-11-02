#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld ep = 1e-8;
const ld pi = 3.14159265358979323846264338327950288L;

struct pnt {
    ld x, y;
    pnt(ld x = 0, ld y = 0) : x(x), y(y) {}
    pnt operator + (const pnt &b) {
        return pnt(x + b.x, y + b.y);
    }
    pnt operator - (const pnt &b) {
        return pnt(x - b.x, y - b.y);
    }
    pnt operator * (const ld &b) {
        return pnt(x * b, y * b);
    }
    pnt operator / (const ld &b) {
        return pnt(x / b, y / b);
    }
    ld operator & (const pnt &b) {
        return x * b.x + y * b.y;
    }
    ld operator ^ (const pnt &b) {
        return x * b.y - b.x * y;
    }
    bool operator < (const pnt &b) const {
        return abs(x - b.x) > ep ? x < b.x : y < b.y;
    }
    bool operator == (const pnt &b) {
        return abs(x - b.x) < ep && abs(y - b.y) < ep;
    }
    bool operator != (const pnt &b) {
        return abs(x - b.x) > ep || abs(y - b.y) > ep;
    }
    pnt rotate(ld alpha) {
        pnt R = pnt(sin(alpha), cos(alpha)), C = *this;
        return pnt(C ^ R, C & R);
    }
    pnt rot() {
        return pnt(-y, x);
    }
    ld dist() {
        return sqrt(x * x + y * y);
    }
    pnt norm() {
        return dist() > ep ? (*this) / dist() : pnt(1, 0);
    }
    void input() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("%.12lf %.12lf\n", x, y);
    }
} p[2];

ld common_area_of_two_circles(pnt c1, ld r1, pnt c2, ld r2) {
    ld r = r1, R = r2, d = (c1 - c2).dist();
    if (r > R) swap(r, R);
    if (r + R <= d) return 0;
    if (r + d <= R) return pi * r * r;
    ld a = 2 * acos((d * d + R * R - r * r) / (2 * d * R));
    ld b = 2 * acos((d * d + r * r - R * R) / (2 * d * r));
    return (R * R * (a - sin(a)) + r * r * (b - sin(b))) / 2;
}

ld r[2];

int main() {
    for (int i = 0; i < 2; i ++) {
        cin >> p[i].x, cin >> p[i].y, cin >> r[i];
    }
    cout.precision(12);
    cout << common_area_of_two_circles(p[0], r[0], p[1], r[1]);
}