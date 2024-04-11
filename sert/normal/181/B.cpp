#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x[3000], y[3000], a[2001][2001], kol = 0;
    int n, k, p, xx, yy;
    cin >> n;
    for (int i = 0; i < 2001; i++)
      for (int j = 0; j < 2001; j++)
        a[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> x[i] >> y[i];
      a[x[i] + 1000][y[i] + 1000] = 1;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i != j)
        {
          xx = (x[i] + x[j]);
          yy = (y[i] + y[j]);
          if (xx % 2 == 0 && yy % 2 == 0)
            if (a[xx / 2 + 1000][yy / 2 + 1000] == 1) kol++;
        }
    cout << kol / 2;
    return 0;
}