#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <cstdio>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
    ll t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    ll at1 = INF;
    ll at2 = 0;
    ll ay1, ay2;

    if (t2 == t0 && t1 == t0)
    {
        cout << x1 << ' ' << x2;
        return 0;
    }
    if (t2 == t0)
    {
        cout << 0 << ' ' << x2;
        return 0;
    }
    if (t1 == t0)
    {
        cout << x1 << ' ' << 0;
        return 0;
    }

    for (ll x = 0; x <= x1; ++x)
    {
        ll l = -1, r = x2;
        while (l < r - 1)
        {
            ll m = (l + r) / 2;
            if (x + m == 0)
            {
                r = 1;
                break;
            }
            if ((t1 * x + t2 * m) / (x + m) >= t0)
                r = m;
            else
                l = m;
        }
        if (r == x2)
            if ((t1 * x + t2 * r) / (x + r) < t0)
                continue;
        ll wx = r;
        /*
        ll wx = (t0 * x - t1 * x) / (t2 - t0);
        if ((t0 * x - t1 * x) % (t2 - t0) != 0)
            wx++;
        if (wx > x2)
            continue;*/
        ll bt1 = t1 * x + t2 * wx;
        ll bt2 = x + wx;
        if ((bt1 * at2 < bt2 * at1)||((bt1 * at2 == bt2 * at1)&&(bt2 > at2)))
        {
            at1 = bt1;
            at2 = bt2;
            ay1 = x;
            ay2 = wx;
        }
        wx = x2;
        bt1 = t1 * x + t2 * wx;
        bt2 = x + wx;
        if ((bt1 * at2 < bt2 * at1)||((bt1 * at2 == bt2 * at1)&&(bt2 > at2)))
        {
            at1 = bt1;
            at2 = bt2;
            ay1 = x;
            ay2 = wx;
        }
    }
    cout << ay1 << ' ' << ay2;
    return 0;
}