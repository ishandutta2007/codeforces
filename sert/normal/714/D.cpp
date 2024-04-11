#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 34;

int res;

int go(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cin >> res;
    return res;
}

void check(int ax1, int ax2, int ay1, int ay2, int bx1, int bx2, int by1, int by2) {
    if (ax1 > ax2 || ay1 > ay2 || bx1 > bx2 || by1 > by2)
        return;
    if (go(ax1, ay1, ax2, ay2) == 1 && go(bx1, by1, bx2, by2) == 1) {
        printf("! %d %d %d %d %d %d %d %d ", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
        cout << endl;
        exit(0);
    }
}

int main() {
    int n;
    cin >> n;

    int xmin, xmax, ymin, ymax;
    int minx, maxx, miny, maxy;
    int l, r, m, x;

    l = 0;
    r = n;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = go(1, 1, n, m);
        if (x == 2)
            r = m;
        else
            l = m;
    }
    ymax = r;
    //cerr << "ymax = " << ymax << "\n";

    l = 0;
    r = n;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = go(1, 1, m, n);
        if (x == 2)
            r = m;
        else
            l = m;
    }
    xmax = r;
    //cerr << "xmax = " << xmax << "\n";

    l = 1;
    r = n + 1;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = go(1, m, n, n);
        if (x == 2)
            l = m;
        else
            r = m;
    }
    ymin = l;
    //cerr << "ymin = " << ymin << "\n";

    l = 1;
    r = n + 1;
    while (r - l > 1) {
        m = (l + r) / 2;
        x = go(m, 1, n, n);
        if (x == 2)
            l = m;
        else
            r = m;
    }
    xmin = l;
    //cerr << "xmin = " << xmin << "\n";

    ///--------------------

    l = 0;
    r = n;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = go(1, 1, n, m);
        if (x >= 1)
            r = m;
        else
            l = m;
    }
    maxy = r;
    //cerr << "maxy = " << maxy << "\n";

    l = 0;
    r = n;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = go(1, 1, m, n);
        if (x >= 1)
            r = m;
        else
            l = m;
    }
    maxx = r;
    //cerr << "maxx = " << maxx << "\n";

    l = 1;
    r = n + 1;
    while (r - l > 1) {
        m = (r + l) / 2;
        x = go(1, m, n, n);
        if (x >= 1)
            l = m;
        else
            r = m;
    }
    miny = l;
    //cerr << "miny = " << miny << "\n";

    l = 1;
    r = n + 1;
    while (r - l > 1) {
        m = (l + r) / 2;
        x = go(m, 1, n, n);
        if (x >= 1)
            l = m;
        else
            r = m;
    }
    minx = l;
    //cerr << "minx = " << minx << "\n";

    check(minx, maxx, miny, maxy, xmin, xmax, ymin, ymax);
    check(minx, xmax, miny, maxy, xmin, maxx, ymin, ymax);

    check(minx, maxx, miny, ymax, xmin, xmax, ymin, maxy);
    check(minx, xmax, miny, ymax, xmin, maxx, ymin, maxy);

    check(minx, maxx, ymin, maxy, xmin, xmax, miny, ymax);
    check(minx, xmax, ymin, maxy, xmin, maxx, miny, ymax);

    check(minx, maxx, ymin, ymax, xmin, xmax, miny, maxy);
    check(minx, xmax, ymin, ymax, xmin, maxx, miny, maxy);

    return 0;
}