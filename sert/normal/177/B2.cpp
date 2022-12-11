#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int sum = 0, n, kol = 0;
    int d[100000] = {0};
    int k[100000] = {0};
    cin >> n;
    int h = n;
    for (int i = 2; i <= sqrt(n); i++)
      if (h % i == 0)
      {
        kol++;
        d[kol] = i;
        while (h % i == 0)
        {
          h /= i;
          k[kol]++;
        }
      }
    if (h != 1)
    {
      kol++;
      d[kol] = h;
      k[kol] = 1;
    }
    h = n;
    sum = n;
    for (int i = 1; i <= kol; i++)
      for (int j = 1; j <= k[i]; j++)
      {
        h /= d[i];
        sum += h;
      }
  cout << sum;
  return 0;
}