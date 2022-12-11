#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, x, y, xx, yy;
    cin >> n >> k;
    cin >> x >> y;
    long double ans = 0;

    for (int i = 1; i < n; i++)
    {
      cin >> xx >> yy;
      ans += sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
      x = xx;
      y = yy;
    }
    ans *= k;
    ans /= 50;
    cout.precision(10);
    cout << fixed << ans;
}