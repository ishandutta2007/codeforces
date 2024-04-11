#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <math.h>

using namespace std;

struct point {double x, y;};
struct line {double A, B, C;};

line build(point A, point B)
{
    line res;
    res.A = A.y - B.y;
    res.B = B.x - A.x;
    res.C = A.x * B.y - A.y * B.x;
    return res;
}

line per(line l, point A)
{
    line res;
    res.A = - l.B;
    res.B = l.A;
    res.C = - (res.A * A.x + res.B * A.y);
    return res;
}

line par(line l, point A)
{
    line res;
    res.A = l.A;
    res.B = l.B;
    res.C = - (res.A * A.x + res.B * A.y);
    return res;
}

point inter(line l1, line l2)
{
    point res;
    res.x = (- l1.C * l2.B + l2.C * l1.B) / (l1.A * l2.B - l2.A * l1.B);
    res.y = (- l1.A * l2.C + l2.A * l1.C) / (l1.A * l2.B - l2.A * l1.B);
    return res;
}

point middle(point A, point B)
{
    point res;
    res.x = (A.x + B.x) / 2.0;
    res.y = (A.y + B.y) / 2.0;
    return res;
}

point sym(point A, point B)
{
    point res;
    res.x = 2.0 * B.x - A.x;
    res.y = 2.0 * B.y - A.y;
    return res;
}

double dist(point A, point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double plos(point A, point B, point C, point D)
{
    double s = fabs(A.x * B.y - B.x * A.y + B.x * C.y - B.y * C.x + C.x * D.y - C.y * D.x + D.x * A.y - D.y * A.x) / 2.0;
    return s;
}

double plos(point A, point B, point C)
{
    double s = fabs(A.x * B.y - A.y * B.x + B.x * C.y - B.y * C.x + C.x * A.y - C.y * A.x) / 2.0;
    return s;
}

bool have;

void print(point A)
{
    printf("%.9lf %.9lf", A.x, A.y);
}

bool check(point A, point B, point C)
{
    double a = dist(B, C), b = dist(A, C), c = dist(A, B);
    return (fabs(a + b - c) <= 1e-9 || fabs(a - b + c) <= 1e-9 || fabs(- a + b + c) <= 1e-9);
}

void solve(point A, point B, point C)
{
    if (have) return;
    line l1 = per(build(A, B), middle(A, B));
    line l2 = per(build(B, C), middle(B, C));
    point D = inter(l1, l2);
    point E = sym(D, B);
    point F = inter(l1, par(l2, E));
    point G = sym(F, B);
    point H = sym(G, C);
    point I = sym(F, A);

    if (fabs(plos(F, G, H, I) - plos(F, G, H) - plos(F, H, I)) < 1e-9 &&
        fabs(plos(F, G, H, I) - plos(F, G, I) - plos(G, H, I)) < 1e-9 && 
        !check(F, G, H) && !check(F, G, I) && !check(F, H, I) && !check(G, H, I))
    {
        have = true;
        printf("YES\n");
        print(I); printf(" ");
        print(F); printf(" ");
        print(G); printf(" ");
        print(H); printf("\n");
    }
}

void solve()
{
    point A, B, C;
    scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
    if (check(A, B, C))
    {
        printf("NO\n\n");
        return;
    }
    have = false;
    solve(A, B, C);
    solve(A, C, B);
    solve(B, C, A);
    solve(B, A, C);
    solve(C, A, B);
    solve(C, B, A);
    if (!have)
    {
        printf("NO\n\n");
        return;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++)
        solve();
    return 0;
}