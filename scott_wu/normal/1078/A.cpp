#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

ll a, b, c;
ld xstart, ystart, xend, yend;

ld xi[4], yi[4];

ld sq (ld x)
{
    return x * x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> a >> b >> c >> xstart >> ystart >> xend >> yend;

    ld gdist = abs (xstart - xend) + abs (ystart - yend);
    cout << fixed << setprecision(9);
    if (a == 0 || b == 0 || xstart == xend || ystart == yend)
    {
        cout << gdist << "\n";
        return 0;
    }

    xi[0] = xstart;
    yi[0] = (-(a * xstart + c) / b);
    xi[1] = xend;
    yi[1] = (-(a * xend + c) / b);

    yi[2] = ystart;
    xi[2] = (-(b * ystart + c) / a);
    yi[3] = yend;
    xi[3] = (-(b * yend + c) / a);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            ld rdist = 0;
            rdist += abs (xstart - xi[i]) + abs (ystart - yi[i]);
            rdist += abs (xi[j] - xend) + abs (yi[j] - yend);
            rdist += sqrt (sq (xi[i] - xi[j]) + sq (yi[i] - yi[j]));
            gdist = min (gdist, rdist);
        }
    cout << gdist << "\n";
    return 0;
}