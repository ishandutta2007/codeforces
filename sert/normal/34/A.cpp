#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;



int main()
{
    int a[100000];
    int n, pos, mn, c, b;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    c = n - 1;
    b = 0;
    for (int i = 1; i < n; i++)
      if (abs(a[i] - a[i - 1]) < abs(a[c] - a[b]))
      {
        c = i - 1;
        b = i;
      }
    cout << c + 1 << " " << b + 1;
    return 0;
}