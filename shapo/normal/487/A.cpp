#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int win(int b, int c, int d)
{
    if (c == 0) {
        return -1;
    }
    int firstTime = (b + c - 1) / c;
    return d * firstTime + 1;
}

int
main()
{
    int yh, ya, yd;
    int mh, ma, md;
    cin >> yh >> ya >> yd;
    cin >> mh >> ma >> md;
    int h, a, d;
    cin >> h >> a >> d;
    int res = 200000 * (h + a + d);
    for (int da = 0; da <= 1000; ++da) {
        for (int dd = 0; dd <= 1000; ++dd) {
            int addH = win(mh, max(0, ya + da - md), max(0, ma - yd - dd));
            if (addH != -1) {
                int diffH = max(0, addH - yh);
                res = min(res, diffH * h + a * da + d * dd);
            }
        }
    }
    cout << res << '\n';
    return 0;
}