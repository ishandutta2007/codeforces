#include <bits/stdc++.h>
using namespace std;

#define N 11

const double ep = 1e-8;
const double inf = 1e9;
struct ball{
    double x, v, m;
    void in() {scanf("%lf %lf %lf", &x, &v, &m);}
    friend void collide(ball &a, ball &b) {
        double v1 = a.v, v2 = b.v;
        a.v = ((a.m - b.m) * v1 + 2 * b.m * v2) / (a.m + b.m);
        b.v = ((b.m - a.m) * v2 + 2 * a.m * v1) / (a.m + b.m);
    }
    friend double time(const ball &a, const ball &b) {
        if (a.v > b.v + ep) {
            if (a.x > b.x - ep) return inf;
            else return (b.x - a.x) / (a.v - b.v);
        }
        else if (a.v < b.v - ep) {
            if (b.x > a.x - ep) return inf;
            else return (a.x - b.x) / (b.v - a.v);
        }
        else return inf;
    }
    inline void go(double t) {
        x += v * t;
    }
    void out() {
        printf("%.8lf\n", x);
    }
} b[N];

int main() {
    int n;
    double t;
    scanf("%d %lf", &n, &t);
    for (int i = 0; i < n; i ++) b[i].in();
    while (1) {
        double mn = inf;
        int x, y;
        for (int i = 0; i < n; i ++) for (int j = 0; j < i; j ++) mn = min(mn, time(b[i], b[j]));
        if (t < mn + ep) {
            for (int i = 0; i < n; i ++) b[i].go(t);
            break;
        }
        for (int i = 0; i < n; i ++) b[i].go(mn);
        t -= mn;
        for (int i = 0; i < n; i ++) for (int j = 0; j < i; j ++) if (abs(b[i].x - b[j].x) < ep) collide(b[i], b[j]);
    }
    for (int i = 0; i < n; i ++) b[i].out();

    return 0;
}