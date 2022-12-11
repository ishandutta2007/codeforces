#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int n, a[100][100], f, s, mx = 0;
    cin >> n;
    n = (n * (n - 1)) / 2 - 1;
    for (int i = 0; i < n; i++)
    {
      cin >> f >> s;
      a[f][s] = 6;
      a[s][f] = -6;
      mx = max(mx, f);
      mx = max(mx, s);
    }
    for (int i = 1; i <= mx; i++)
      a[i][i] = 6;
    for (int i = 1; i <= mx; i++)
      for (int j = 1; j <= mx; j++)
        if (abs(a[i][j]) != 6)
        {
          f = i;
          s = j;
        }
    for (int i = 1; i <= mx; i++)
      if ((i - s) * (i - f) != 0)
        if (a[s][i] == a[i][f])
          if (a[s][i] == 6)
          {
            cout << s << " " << f;
            return 0;
          }
          else
          {
            cout << f << " " << s;
            return 0;
          }


    cout << f << " " << s;
  return 0;
}