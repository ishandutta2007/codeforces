#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int MXN = 1e3 + 10;
int n, m, r, t, res[MXN];
struct Point
{
    int a, b, c, d, e;
};
Point A[MXN];
int Dist(Point X, Point Y)
{
    int rr = 0;
    rr += X.a * Y.a;
    rr += X.b * Y.b;
    rr += X.c * Y.c;
    rr += X.d * Y.d;
    rr += X.e * Y.e;
    return (rr);
}
int Calc(int i, int j, int h)
{
    Point X, Y;
    X.a = A[j].a - A[i].a;
    X.b = A[j].b - A[i].b;
    X.c = A[j].c - A[i].c;
    X.d = A[j].d - A[i].d;
    X.e = A[j].e - A[i].e;
    Y.a = A[h].a - A[i].a;
    Y.b = A[h].b - A[i].b;
    Y.c = A[h].c - A[i].c;
    Y.d = A[h].d - A[i].d;
    Y.e = A[h].e - A[i].e;
    long double rr = Dist(X, Y);
    long double xx = sqrt(Dist(X, X));
    long double yy = sqrt(Dist(Y, Y));
    if (rr / (xx * yy) > 0)
        return (0);
    return (1);
}
int main()
{
    scanf("%d", &n);
    if (n >= 20)
        return printf("0"), 0;
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d%d", &A[i].a, &A[i].b, &A[i].c, &A[i].d, &A[i].e), res[i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int h = j + 1; h <= n; h++)
            {
                if (i == j || i == h)
                    continue;
                if (Calc(i, j, h) == 0)
                    res[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        r += (res[i]);
    printf("%d\n", r);
    for (int i = 1; i <= n; i++)
        if (res[i] == 1)
            printf("%d ", i);
    return (0);
}