#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long a, b, c;

void gcd(long long a, long long b, long long &x, long long &y, long long &d)
{
    long long x1 = 1LL, y1 = 0LL, r1 = a;
    long long x2 = 0LL, y2 = 1LL, r2 = b;

    while (r2)
    {
        long long q = r1 / r2;
        r1 -= r2 * q; swap(r1, r2);
        x1 -= x2 * q; swap(x1, x2);
        y1 -= y2 * q; swap(y1, y2);
    }

    x = x1, y = y1;
    d = r1;
}

int main()
{
    cin >> a >> b >> c;

    long long x, y, d;
    gcd(a, b, x, y, d);

    if (c % d != 0) printf("-1\n"); else
    {
        if (c == 0) cout << b << " " << -a << endl; else
        {
            long long q = - c / d;
            cout << x * q << " " << y * q << endl;
        }
    }

    return 0;
}