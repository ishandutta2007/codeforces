#include<bits/stdc++.h>
using namespace std;
long long a, b, c, d, e;
long double l, r, mid,t, p;
int main()
{
    scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
    if (a * d == b * c)
    {
        cout << 0;
        return (0);
    }
    if (a * d > b * c)
    {
        e = a;
        a = c;
        c = e;
        e = b;
        b = d;
        d = e;
    }
    r = 1.0 * 1e18;
    while (r - l > 1e-10)
    {
        mid = (l + r) / 2;
        t = max((1.0 * a + mid) * (1.0 * d + mid), (1.0 * a - mid) * (1.0 * d - mid));
        t = max(max((1.0 * a + mid) * (1.0 * d - mid), (1.0 * a - mid) * (1.0 * d + mid)), t);
        p = min((1.0 * b - mid) * (1.0 * c - mid), (1.0 * b + mid) * (1.0 * c + mid));
        p = min(min((1.0 * b - mid) * (1.0 * c + mid), (1.0 * b + mid) * (1.0 * c - mid)), p);
        if (t < p)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout.precision(10);
    cout << fixed << r;
    return (0);
}