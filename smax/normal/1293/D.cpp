#include <bits/stdc++.h>
using namespace std;

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

    vector<long long> x, y;
    x.push_back(x0);
    y.push_back(y0);
    while (x.back() * ax + bx <= xs + t && y.back() * ay + by <= ys + t) {
        x.push_back(x.back() * ax + bx);
        y.push_back(y.back() * ay + by);
    }

    int ret = 0;
    for (int i=0; i<x.size(); i++)
        for (int j=i; j<x.size(); j++) {
            long long len = dist(x[i], y[i], x[j], y[j]), lft = dist(x[i], y[i], xs, ys), rght = dist(x[j], y[j], xs, ys);
            if (len + lft <= t || len + rght <= t)
                ret = max(ret, j - i + 1);
        }

    cout << ret << "\n";

    return 0;
}