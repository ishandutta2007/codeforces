#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a[200], n, k;
    for (int i = 0; i <= 200; i++)
      a[i] = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> k;
      a[k]++;
    }
    int kol = 0;
    for (int i = 1; i <= 198; i++)
      kol += a[i] / 2;
    cout << kol / 2;
    return 0;
}