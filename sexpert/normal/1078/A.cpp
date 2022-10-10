#include <bits/stdc++.h>
using namespace std;
typedef pair<long double, long double> pt;

const long double eps = 1e-2;

long double dist(pt p1, pt p2)
{
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

long double pdist(pt p1, pt p2, pt p3, pt p4)
{
    return abs(p1.first - p2.first) + abs(p1.second - p2.second) + dist(p2, p3) + abs(p3.first - p4.first) + abs(p3.second - p4.second);
}

int main()
{
    long double a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    pt A = {x1, y1}, B = {x2, y2};
    cout << fixed << setprecision(20);
    if(abs(a) < eps || abs(b) < eps)
    {
        cout << abs(x1 - x2) + abs(y1 - y2) << endl;
        return 0;
    }
    pt ha, va, hb, vb;
    // horizontal from A
    ha.second = y1;
    ha.first = (-b*y1 - c)/a;
    // horizontal from B
    hb.second = y2;
    hb.first = (-b*y2 - c)/a;
    // vert from A
    va.first = x1;
    va.second = (-a*x1 - c)/b;
    // vert from B
    vb.first = x2;
    vb.second = (-a*x2 - c)/b;

    long double ans = abs(A.first - B.first) + abs(A.second - B.second);
    /*cout << ha.first << " " << ha.second << endl;
    cout << hb.first << " " << hb.second << endl;
    cout << va.first << " " << va.second << endl;
    cout << vb.first << " " << vb.second << endl;*/
    ans = min(ans, pdist(A, ha, hb, B));
    ans = min(ans, pdist(A, ha, vb, B));
    ans = min(ans, pdist(A, va, hb, B));
    ans = min(ans, pdist(A, va, vb, B));

    cout << ans << endl;
}