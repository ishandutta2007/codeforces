#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
bool have(long long x1, long long y1, long long x2, long long y2, long long x, long long y)
{
    //double a = dist(x1,y1,x2,y2), b = dist(x1,y1,x,y), c = dist(x,y,x2,y2);
    long long A = y1 - y2;
    long long B = x2 - x1;
    long long C = (x1 * y2 - x2 * y1);

    if (A * x + B * y + C != 0LL) return false;

    long long a = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    long long b = (x1-x)*(x1-x)+(y1-y)*(y1-y);
    long long c = (x2-x)*(x2-x)+(y2-y)*(y2-y);

    if (b > a || c > a) return false;
    if (b > c) swap(b, c);
    return (16LL * b >= c);
}

bool solve()
{
    long long x1[4], y1[4], x2[4], y2[4];
    for (int i = 1; i <= 3; i ++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        x1[i] = a, y1[i] = b, x2[i] = c, y2[i] = d;
    }

    int p = -1, q = -1, l = -1;

    for (int i = 1; i <= 3; i ++)
        for (int j = i + 1; j <= 3; j ++)
        {
            if (x1[i] == x1[j] && y1[i] == y1[j]) p = i, q = j;
            if (x1[i] == x2[j] && y1[i] == y2[j]) p = i, q = j;
            if (x2[i] == x1[j] && y2[i] == y1[j]) p = i, q = j;
            if (x2[i] == x2[j] && y2[i] == y2[j]) p = i, q = j;
        }

    if (p == -1 || q == -1) return false;

    l = 1;
    if (p == 1 && q == 2) l = 3;
    if (p == 1 && q == 3) l = 2;

    if (x1[p] == x2[q] && y1[p] == y2[q]) swap(x1[q], x2[q]), swap(y1[q], y2[q]); else
    if (x2[p] == x1[q] && y2[p] == y1[q]) swap(x1[p], x2[p]), swap(y1[p], y2[p]); else
    if (x2[p] == x2[q] && y2[p] == y2[q]) swap(x1[q], x2[q]), swap(y1[q], y2[q]), swap(x1[p], x2[p]), swap(y1[p], y2[p]);

    double a = dist(x1[p],y1[p],x2[p],y2[p]);
    double b = dist(x1[q],y1[q],x2[q],y2[q]);
    double c = dist(x2[p],y2[p],x2[q],y2[q]);

    double cs = (a * a + b * b - c * c) / 2.0 / a / b;

    if (cs >= 0 && cs < 1)
    {
        if (have(x1[p],y1[p],x2[p],y2[p],x1[l],y1[l]) && have(x1[q],y1[q],x2[q],y2[q],x2[l],y2[l])) return true;
        if (have(x1[p],y1[p],x2[p],y2[p],x2[l],y2[l]) && have(x1[q],y1[q],x2[q],y2[q],x1[l],y1[l])) return true;
    }

    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i ++)
    {
        int gd = solve();
        if (gd) printf("YES\n"); else printf("NO\n");
    }

    return 0;
}