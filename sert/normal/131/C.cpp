#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;



int main()
{
    long long c[50][50], n, m, t, ans = 0, k, p;
    for (int i = 0; i < 50; i++)
      for (int j = 0; j < 50; j++)
        c[i][j] = 0;

    c[1][1] = 1;
    for (int i = 2; i < 50; i++)
      for (int j = 1; j < 50; j++)
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    cin >> n >> m >> t;
    k = 4;
    p = t - k;
    while (p > m)
    {
      p--;
      k++;
    }
    while (k <= n && p > 0)
    {
      ans += c[n + 1][k + 1] * c[m + 1][p + 1];
      k++;
      p--;
    }
    cout << ans;
    return 0;
}