#include <string>
#include <fstream>;
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const long double malo = 1e-14;

long long r, x, y, xx, yy;
long double d;

int main() {
    cin >> r >> x >> y >> xx >> yy;
    d = sqrtl((xx - x) * (xx - x) + (yy - y) * (yy - y));
    d = (d + 2 * r - malo) / (2.0 * r);
    r = d;
    cout << r;
}