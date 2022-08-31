#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int xlo, ylo, xhi, yhi;
int llo, lhi, rlo, rhi;

bool is_in (int x, int y)
{
    int len = (lhi - llo) / 2;
    if (x < llo || x > lhi || y < rlo || y > rhi)
        return false;

    int xd = min (x - llo, lhi - x);
    int yd = min (y - rlo, rhi - y);
    if (xd + yd < len)
        return false;
    return true;
}

int main()
{
    xlo = ylo = llo = rlo = 10000;
    xhi = yhi = lhi = rhi = -10000;
    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        xlo = min (xlo, x);
        xhi = max (xhi, x);
        ylo = min (ylo, y);
        yhi = max (yhi, y);
    }

    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        llo = min (llo, x);
        lhi = max (lhi, x);
        rlo = min (rlo, y);
        rhi = max (rhi, y);
    }

    bool b = false;
    for (int i = xlo; i <= xhi; i++)
        for (int j = ylo; j <= yhi; j++)
        {
            if (is_in(i, j))
                b = true;
        }

    if (b) cout << "YES\n";
    else cout << "NO\n";
}