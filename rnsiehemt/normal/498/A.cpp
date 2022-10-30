#include <bits/stdc++.h>

const double eps = 1e-9;

struct P {
    double x, y;
    P() : x(0), y(0) { }
    P(double xx, double yy) : x(xx), y(yy) { }
};

P operator-(P a, P b) {
    return P(a.x-b.x, a.y-b.y);
}

double operator^(P a, P b) {
    return a.x*b.y-a.y*b.x;
}

double norm(double a) {
    if (a < -eps) return -1.0;
    else if (a > eps) return 1.0;
    else return 0.0;
}

P p, q;
int N;
int ans;

int main()
{
    scanf("%lf%lf", &p.x, &p.y);
    scanf("%lf%lf", &q.x, &q.y);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        double a, b, c; scanf("%lf%lf%lf", &a, &b, &c);
        P u, v;
        if (b != 0) {
            u = P(0, -c/b);
            v = P(1, -(c+a)/b);
        }
        else {
            u = P(-c/a, 0);
            v = P(-c/a, 1);
        }
        if (norm((p-u)^(u-v)) * norm((q-u)^(u-v)) < 0.0)
            ans++;
    }
    printf("%d\n", ans);
}