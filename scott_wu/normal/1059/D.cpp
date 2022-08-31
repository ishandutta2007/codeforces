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
const int MAXN = 100100;

int N;
ld x[MAXN], y[MAXN];

bool works (ld R)
{
    ld xlo = -1e12, xhi = 1e12;
    for (int i = 0; i < N; i++)
    {
        ld v = 2 * R - y[i];
        if (v < 0) return false;
        ld xjump = sqrt (v * y[i]);
        xlo = max (xlo, x[i] - xjump);
        xhi = min (xhi, x[i] + xjump);
    }
    return xlo <= xhi;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int xc, yc;
        cin >> xc >> yc;
        x[i] = xc;
        y[i] = yc;
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (y[i] * y[i+1] < 0)
        {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < N; i++)
        if (y[i] < 0) y[i] = -y[i];

    ld lo = 0.0, hi = 1e15;
    for (int i = 0; i < 200; i++)
    {
        ld mid = (lo + hi) / 2.;
        if (works (mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed << setprecision(8);
    cout << lo << "\n";
}