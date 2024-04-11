#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

const double eps = 1e-9;

double a, b, c, d;

void bail() {
    printf("42\n");
    exit(0);
}

void arith() {
    if (b-a == c-b && c-b == d-c) {
        printf("%d\n", int(round(d + d-c)));
        exit(0);
    }
}

void geom() {
    if (std::abs(b/a - c/b) < eps && std::abs(d/c - c/b) < eps) {
        double e = d*(d/c);
        if (std::abs(e - round(e)) < eps) {
            printf("%d\n", int(round(e)));
            exit(0);
        }
        else bail();
    }
    else bail();
}

int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    arith();
    geom();
}