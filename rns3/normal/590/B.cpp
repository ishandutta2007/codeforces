#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double pi = acos(-1);

double x, y;
double vmax, t;
double vx, vy;
double wx, wy;

bool cango(double T) {
    double xx, yy;
    if (T <= t) {
        xx = T * vx, yy = T * vy;
    } else {
        xx = t * vx + (T - t) * wx;
        yy = t * vy + (T - t) * wy;
    }
    xx = x - xx;
    yy = y - yy;
    double d = sqrt(xx * xx + yy * yy);
    return d <= vmax * T;
}

int main() {
   // freopen("B.in","r",stdin);
    double xx, yy, x2, y2;
    scanf("%lf %lf %lf %lf",&xx,&yy,&x2,&y2);
    x = x2 - xx, y = y2 - yy;
    scanf("%lf %lf",&vmax,&t);
    scanf("%lf %lf",&vx,&vy);
    scanf("%lf %lf",&wx,&wy);
    double mn = 0, mx = 1e9;
    for (int i = 0; i < 100; i++) {
        double mid = (mn + mx) / 2;
        if (cango(mid)) mx = mid;
        else mn = mid;
    }
    printf("%.10lf\n", mn);
}