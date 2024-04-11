#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

void lmin(int& x, int& y) {
    if (x > y) {
        swap(x, y);
    }
}

int sdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lmin(x1, x2);
    lmin(y1, y2);
    vector<point> g;
    for (int i = x1; i < x2; ++i) {
        g.push_back(point{i, y1});
        g.push_back(point{i, y2});
    }
    for (int i = y1; i < y2; ++i) {
        if (i > y1) {
            g.push_back(point{x1, i});
        }
        g.push_back(point{x2, i});
    }
    g.push_back(point{x2, y2});
    vector<bool> cold(g.size(), true);

    int n;
    cin >> n;
    for (int q = 0; q < n; ++q) {
        int x, y, r;
        cin >> x >> y >> r;
        point cp{x, y};
        for (int i = 0; i < g.size(); ++i) {
            if (sdist(cp, g[i]) <= r * r) {
                cold[i] = false;
            }
        }
    }
    int cou = 0;
    for (int i = 0; i < g.size(); ++i) {
        if (cold[i]) {
            ++cou;
        }
    }
    cout << cou << '\n';

    return 0;
}