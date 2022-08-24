#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

ld a, b, c, d;

pair <ld, ld> range (ld x, ld f, ld f2)
{
    ld n = (f - x) * (f2 - x), n2 = (f - x) * (f2 + x), n3 = (f + x) * (f2 - x), n4 = (f + x) * (f2 + x);
    
    ld m = min (min (n, n2), min (n3, n4));
    ld m2 = max (max (n, n2), max (n3, n4));
    return make_pair (m, m2);
}

bool works (ld x)
{
    pair <ld, ld> r1 = range (x, a, d), r2 = range (x, b, c);
    //cout << r1.first << " " << r1.second << " " << r2.first << " " << r2.second << "\n";
    return r1.second >= r2.first && r2.second >= r1.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> a >> b >> c >> d;
    
    ld lo = 0, hi = 1e9;
    for (int t = 0; t < 150; t++)
    {
        ld mid = (lo + hi) / 2.0;
        if (works (mid))
            hi = mid;
        else
            lo = mid;
    }
    
    cout << fixed << setprecision(10);
    cout << lo << "\n";
    return 0;
}