#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

typedef long long lol;

const double eps = 1e-9;

double a, b, c, nx, mx, ny, my, ans;
lol ax, ay, bx, by;

int main() {
    std::cin >> a >> b >> c >> ax >> ay >> bx >> by; ans = std::abs(ax - bx) + std::abs(ay - by);
    if ((a < eps && a > -eps) || (b < eps && b > -eps)) { printf("%.7lf\n", ans); return 0; }
    nx = -b / a, mx = -c / a, ny = -a / b, my = -c / b;
    ans = std::min(ans, std::abs(ay - (ny * ax + my)) + std::abs(by - (ny * bx + my)) + sqrt((ax - bx) * (ax - bx) + ((ny * ax + my) - (ny * bx + my)) * ((ny * ax + my) - (ny * bx + my))));
    ans = std::min(ans, std::abs(ax - (nx * ay + mx)) + std::abs(bx - (nx * by + mx)) + sqrt((ay - by) * (ay - by) + ((nx * ay + mx) - (nx * by + mx)) * ((nx * ay + mx) - (nx * by + mx))));
    ans = std::min(ans, std::abs(ay - (ny * ax + my)) + std::abs(bx - (nx * by + mx)) + sqrt((ax - (nx * by + mx)) * (ax - (nx * by + mx)) + ((ny * ax + my) - by) * ((ny * ax + my) - by)));
    ans = std::min(ans, std::abs(ax - (nx * ay + mx)) + std::abs(by - (ny * bx + my)) + sqrt((ay - (ny * bx + my)) * (ay - (ny * bx + my)) + ((nx * ay + mx) - bx) * ((nx * ay + mx) - bx)));
    printf("%.7lf\n", ans);
    return 0;
} //