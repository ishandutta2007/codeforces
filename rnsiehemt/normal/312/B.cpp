#include <cstdio>

typedef double real;

double a, b, c, d;
double p, l;

int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    l = 1.0;
    while (l >= 1e-8) {
        p += l*a/b;
        l -= l*a/b;
        l -= l*c/d;
    }

    printf("%.7lf\n", p);
}