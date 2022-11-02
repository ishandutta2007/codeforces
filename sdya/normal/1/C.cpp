#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

void solve(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double s = fabs(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3)/2.0;
    double a = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    double b = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    double c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    double r = a * b * c / s / 4.0;
    double a1, a2, a3;

    a1 = 2.0 * acos((b * b + c * c - a * a) / b / c / 2.0);
    a2 = 2.0 * acos((a * a + c * c - b * b) / a / c / 2.0);
    a3 = 2.0 * acos((b * b + a * a - c * c) / a / b / 2.0);

    for (int i = 1; i <= 100; i ++)
    {
        double x = (4 * acos(0.0)) / (double)(i);
        int s = (int)((a1 + 1e-6) / x);
        int p = (int)((a2 + 1e-6) / x);
        int q = (int)((a3 + 1e-6) / x);

        if (s + p + q == i)
        {
            double n = (double)(i);
            printf("%.12lf\n", n / 2.0 * r * r * sin(4.0 * acos(0.0) / n));
            return;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    solve(x1, y1, x2, y2, x3, y3);
    return 0;
}