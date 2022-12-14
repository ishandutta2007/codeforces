// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
using namespace std;

typedef complex<double> point;
const int N = (int) 1e6 + 6, mod = (int) 0;
#define px real()
#define py imag()


point p[N], o;
point rotate(point x, point a, point b) { return (x - a) / polar(1.0, arg(b - a)); }
int n;
double cross(point a, point b) { return a.px * b.py - a.py * b.px; }
double area(point a, point b) { return abs(cross(a - o, b - o)) / 2; } 
double solve() {
    int best = n;
    double res = 1e15, cur_area = 0;
    for (int cur = n; cur < n + n; ++cur) {
        int pr = cur - 1;
        while (best < cur)
            cur_area += area(p[best], p[best + 1]), best++;
        while (rotate(p[best], p[cur], p[pr]).px > rotate(p[best + 1], p[cur], p[pr]).px)
            cur_area += area(p[best], p[best + 1]), best++;
        point rotated = rotate(p[best], p[cur], p[pr]);
        res = min(res, -cur_area + area(p[cur], p[best]) + abs(rotated.px * rotated.py) / 2);
        cur_area -= area(p[cur], p[cur + 1]);
    }
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int j = 0; j < n; ++j) {
        int x, y;
        cin >> x >> y;
        p[j] = point(x, y);
        o += p[j];
    }
    o /= n;
    for (int j = n; j < n + n + n; ++j)
        p[j] = p[j - n];
    double res = solve();
    reverse(p, p + 3 * n);
    res = min(res, solve());
    cout << setprecision(7) << fixed << res << endl;
}