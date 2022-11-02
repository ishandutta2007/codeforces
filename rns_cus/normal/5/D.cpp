#include <bits/stdc++.h>
using namespace std;

double a, v, l, d, w;

double solve(double x, double y, double d) {
    double t = (sqrt(x * x + 2 * a * d) - x) / a;
    if (x + a * t < y) return t;
    t = (y - x) / a;
    return t + (d - (x * t + a * t * t / 2)) / y;
}

int main() {
    scanf("%lf %lf %lf %lf %lf", &a, &v, &l, &d, &w);
    w = min(w, v);
    double t = w / a;
    double x = a * t * t / 2;
    if (x <= d) printf("%.6lf\n", t + solve(w, v, l - d) + 2 * solve(w, v, (d - x) / 2));
    else printf("%.6lf\n", solve(0, v, l));

    return 0;
}