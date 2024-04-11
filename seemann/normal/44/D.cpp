#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

#define clr(a) memset(a, 0, sizeof(a))
#define fori(a) for(int i = 0; i < a; i++)
#define forj(a) for(int j = 0; j < a; j++)
#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define ll long long


using namespace std;
const double eps = 0.000000001;


struct planet{
    double x, y, z, d;
};

double dist(planet a, planet b)
{
    return (sqrt ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z)));
}

planet p[5005];

int n;

int main()
{

    scanf("%d", &n);
    fori(n)
    {
        scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
        p[i].d = dist(p[0], p[i]);
    }
    double min = 2000000000.0;

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            double w = (dist(p[i], p[j]) + p[i].d + p[j].d);
            if (min - w > eps) min = w;
        }

    printf("%.7lf", min / 2);


    return 0;
}