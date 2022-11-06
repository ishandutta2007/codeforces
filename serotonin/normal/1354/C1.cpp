#include <bits/stdc++.h>
using namespace std;

int n;

const double pi = acos(-1.0), eps = 1e-10;

double fnc(double ang)
{
    double rx = 0, lx = 0, ry = 0, ly = 0;
    double shaft = pi / n, x = 0, y = 0;
    for(int i=1; i<n*2; i++) {
        x += cos(ang);
        y += sin(ang);
        ang += shaft;
        rx = max(rx, x), lx = min(lx, x);
        ry = max(ry, y), ly = min(ly, y);
    }
    return max(rx - lx, ry - ly);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        double lo = 0, hi = pi / 2;
        while(hi - lo > eps) {
            double m1 = (2 * lo + hi) / 3;
            double m2 = (lo + hi * 2) / 3;
            if(fnc(m1) < fnc(m2)) hi = m2;
            else lo = m1;
        }
        printf("%.9f\n", fnc(lo));
    }
}