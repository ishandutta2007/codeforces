#include <iostream>
#include <math.h>

using namespace std;

double a, v;
double l, d, w;

double solve(double a, double v, double l)
{
     double t = sqrt(2.0 * l / a);
     if (a * t <= v) return t;

     double t1 = v / a;

     double s1 = l - (a * t1 * t1 / 2.0);
     double t2 = s1 / v;

     return t1 + t2;
}

int main()
{
    scanf("%lf%lf", &a, &v);
    scanf("%lf%lf%lf", &l, &d, &w);

    if (v <= w)
    {
        printf("%.10lf\n", solve(a, v, l));
    } else
    {
        double t = sqrt(2.0 * d / a);
        if (a * t <= w)
        {
            printf("%.10lf\n", solve(a, v, l));
        } else
        {
            double t1 = w / a;
            double s = a * t1 * t1 / 2.0;
            double t2 = solve(a, v, (s + d) / 2.0);
            double t3 = solve(a, v, l - (d - s));
            printf("%.10lf\n", t3 + 2.0 * (t2 - t1));
        }
    }

    return 0;
}