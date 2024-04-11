#include <iostream>

using namespace std;

int n;
double a[20][20];

double p[1 << 18];

double calc(int mask)
{
    if (p[mask] > -0.5) return p[mask];

    p[mask] = 0.0;
    double bits = 1.0;
    for (int i = 0; i < n; i ++)
        if ((mask & (1 << i)) != 0) bits += 1.0;
    bits *= (bits - 1.0) / 2.0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            if ((mask & (1 << i)) != 0 && (mask & (1 << j)) == 0)
                p[mask] += calc(mask | (1 << j)) * a[i][j] / bits;
    return p[mask];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            scanf("%lf", &a[i][j]);

    for (int i = 0; i < (1 << n); i ++)
        p[i] = -1.0;
    p[(1 << n) - 1] = 1.0;
    for (int i = 0; i < n; i ++)
        printf("%.10lf ", calc(1 << i));
    return 0;
}