#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
// const int inf = 1e18;

#define double long double

const double R3 = sqrtl(3);
const double PI = acosl(-1);

double dist2(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double angle(double x1, double y1, double x2, double y2) {
    return acosl((x1 * x2 + y1 * y2) / (sqrtl(x1 * x1 + y1 * y1) * sqrtl(x2 * x2 + y2 * y2)));
}

double fermat(double x1, double y1, double x2, double y2, double x3, double y3) {
    if (angle(x2 - x1, y2 - y1, x3 - x1, y3 - y1) > 2 * PI / 3)
        return sqrtl(dist2(x1, y1, x2, y2)) + sqrtl(dist2(x1, y1, x3, y3));
    if (angle(x1 - x2, y1 - y2, x3 - x2, y3 - y2) > 2 * PI / 3)
        return sqrtl(dist2(x1, y1, x2, y2)) + sqrtl(dist2(x2, y2, x3, y3));
    if (angle(x1 - x3, y1 - y3, x2 - x3, y2 - y3) > 2 * PI / 3)
        return sqrtl(dist2(x1, y1, x3, y3)) + sqrtl(dist2(x2, y2, x3, y3));
    return sqrtl((dist2(x1, y1, x2, y2) + dist2(x1, y1, x3, y3) + dist2(x2, y2, x3, y3)) / 2 + R3 * abs((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    auto calc = [&] (double x, double y) -> double {
        return max({fermat(x, y, x1, y1, x2, y2), fermat(x, y, x1, y1, x3, y3), fermat(x, y, x2, y2, x3, y3)});
    };

    auto check = [&] (double x) -> double {
        double l = -1e5, r = 1e5;
        for (int rep=0; rep<200; rep++) {
            double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            if (calc(x, m1) > calc(x, m2))
                l = m1;
            else
                r = m2;
        }
        return calc(x, l);
    };

    double l = -1e5, r = 1e5;
    for (int rep=0; rep<200; rep++) {
        double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (check(m1) > check(m2))
            l = m1;
        else
            r = m2;
    }
    cout << fixed << setprecision(10) << check(l) << "\n";

    return 0;
}