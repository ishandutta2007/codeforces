#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;

ll N;
ll xlo, xhi, ylo, yhi;

int get_res (ll left, ll right)
{
    cout << left << " " << right << "\n" << flush;
    int c;
    cin >> c;
    return c;
}

int main()
{
    cin >> N;
    xlo = 1;
    xhi = N;
    ylo = 1;
    yhi = N;
    ll xtop = N, ytop = N;

    int c = 0;
    while (xlo < xhi || ylo < yhi)
    {
        ll xmid, ymid;
        if (c % 2 == 0)
        {
            xmid = (xlo + xhi) / 2;
            ymid = yhi;
        }
        else
        {
            xmid = xhi;
            ymid = (ylo + yhi) / 2;
        }
        c++;

        int g = get_res (xmid, ymid);
        if (g == 0) return 0;
        if (g == 1)
        {
            if (xmid >= xhi)
            {
                ytop = yhi;
                xlo = xmid + 1;
                xhi = xtop;
            }
            else
            {
                xlo = xmid + 1;
            }
        }
        else if (g == 2)
        {
            if (ymid >= yhi)
            {
                xtop = xhi;
                ylo = ymid + 1;
                yhi = ytop;
            }
            else
            {
                ylo = ymid + 1;
            }
        }
        else
        {
            xhi = min (xhi, xmid);
            yhi = min (yhi, ymid);
        }
    }
    //cout << xlo << " " << ylo << "\n"; // one of these should hold equality
    int g = get_res (xlo, ylo);
    if (g == 0) return 0;
    if (g == 1)
    {
        // Y set, bin search x
        xhi = N;
        while (xlo < xhi)
        {
            ll xmid = (xlo + xhi) / 2;
            ll ymid = ylo;

            int g = get_res (xmid, ymid);
            if (g == 0) return 0;
            if (g == 1)
            {
                xlo = xmid + 1;
            }
            else
            {
                xhi = xmid - 1;
            }
        }
    }
    else if (g == 2)
    {
        // X set, bin search y
        yhi = N;
        while (ylo < yhi)
        {
            ll xmid = xlo;
            ll ymid = (ylo + yhi) / 2;

            int g = get_res (xmid, ymid);
            if (g == 0) return 0;
            if (g == 2)
            {
                ylo = ymid + 1;
            }
            else
            {
                yhi = ymid - 1;
            }
        }

    }
    get_res (xlo, ylo);
    return 0;
}