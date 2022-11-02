#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef long double real;

const real eps = 1e-22L;

real a, b, c, d;
real min, max;

void domin(real &p, real q) { p = std::min(p, q); }
void domax(real &p, real q) { p = std::max(p, q); }
void f(real l1, real r1, real l2, real r2) {
    min = 1e25L; max = -1e25L;
    domin(min, l1*l2); domax(max, l1*l2);
    domin(min, l1*r2); domax(max, l1*r2);
    domin(min, r1*l2); domax(max, r1*l2);
    domin(min, r1*r2); domax(max, r1*r2);
}

int main()
{
    ll aa, bb, cc, dd; scanf("%lld%lld%lld%lld", &aa, &bb, &cc, &dd);
    a = aa; b = bb; c = cc; d = dd;
    real lo = 0.0L, hi = 1e25L;
    //printf("%Lf %Lf %.14Lf\n", lo, hi, eps);
    for (int i = 0; i < 300; i++) {
        real mid = (lo+hi)/2.0L;
        f(a-mid, a+mid, d-mid, d+mid);
        real amin = min, amax = max;
        f(b-mid, b+mid, c-mid, c+mid);
        real bmin = -max, bmax = -min;
        if (amin + bmin < eps && amax + bmax > -eps) hi = mid;
        else lo = mid;
    }
    double ans = lo; printf("%.11lf\n", ans);
}