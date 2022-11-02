#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

struct P {
    double x, y;
    P() : x(0.0), y(0.0) { }
    P(double xx, double yy) : x(xx), y(yy) { }
};

P operator*(P a, double t) {
    return P(a.x * t, a.y * t);
}
P operator+(P a, P b) {
    return P(a.x + b.x, a.y + b.y);
}
P operator-(P a, P b) {
    return P(a.x - b.x, a.y - b.y);
}
double size(P a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

P a, b, u, v;
double s, t;

int main()
{
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &s, &t, &u.x, &u.y, &v.x, &v.y);
    b = b - a;
    
    if (size(b - u*t) <= (s*t) + 1e-9) {
        double lo = 0, hi = t;
        for (int i = 0; i < 1000; i++) {
            double mid = (lo+hi)/2;
            if (size(b - u*mid) <= s*mid) hi = mid;
            else lo = mid;
        }
        printf("%.8lf\n", lo);
    } else {
        double lo = 0, hi = 1e11;
        for (int i = 0; i < 1000; i++) {
            double mid = (lo+hi)/2;
            if (size(u*t - (b - v*mid)) <= (t+mid)*s) hi = mid;
            else lo = mid;
        }
        printf("%.8lf\n", lo + t);
    }
}