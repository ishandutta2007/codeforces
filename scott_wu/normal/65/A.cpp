#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

int main()
{
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long totala = 1;
    long long totalb = 1;
    totala = b * d * f;
    totalb = a * c * e;
    if (c == 0 && d > 0)
    {
          cout << "Ron";
          return 0;
    }
    if (a == 0 && b > 0 && d > 0)
    {
          cout << "Ron";
          return 0;
    }
    if (e == 0 && b > 0 && d > 0 && f > 0)
    {
          cout << "Ron";
          return 0;
    }
    if (totala > totalb)
       cout << "Ron";
    else
        cout << "Hermione";
    return 0;
}