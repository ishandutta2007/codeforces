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

int xa, ya, xb, yb, xc, yc;
int x[3], y[3];


vector <pair <int, int> > res;
vector <pair <int, int> > ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    x[0] = xa;
    x[1] = xb;
    x[2] = xc;
    y[0] = ya;
    y[1] = yb;
    y[2] = yc;

    sort (x, x + 3);
    sort (y, y + 3);
    for (int i = y[0]; i <= y[2]; i++)
        res.push_back (make_pair (x[1], i));

    if (xa != x[1])
    {
        int lo, hi;
        if (xa < x[1])
        {
            lo = xa;
            hi = x[1] - 1;
        }
        else
        {
            lo = x[1] + 1;
            hi = xa;
        }

        for (int i = lo; i <= hi; i++)
            res.push_back(make_pair (i, ya));
    }
    if (xb != x[1])
    {
        int lo, hi;
        if (xb < x[1])
        {
            lo = xb;
            hi = x[1] - 1;
        }
        else
        {
            lo = x[1] + 1;
            hi = xb;
        }

        for (int i = lo; i <= hi; i++)
            res.push_back(make_pair (i, yb));
    }
    if (xc != x[1])
    {
        int lo, hi;
        if (xc < x[1])
        {
            lo = xc;
            hi = x[1] - 1;
        }
        else
        {
            lo = x[1] + 1;
            hi = xc;
        }

        for (int i = lo; i <= hi; i++)
            res.push_back(make_pair (i, yc));
    }

    sort (res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        if (i == 0 || res[i] != res[i-1])
            ans.push_back(res[i]);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}