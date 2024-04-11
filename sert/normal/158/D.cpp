#include <iostream>

using namespace std;

int main()
{
    int a[20003], b[20003], sum[20003], k, n, kol = 0, h, max;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 3; i <= n; i++)
      if (n % i == 0)
      {
        kol++;
        b[kol] = i;
      }
    max = -1000000000;
    for (int i = 1; i <= kol; i++)
    {
      for (int j = 0; j <= 20000; j++)
        sum[j] = 0;
      h = n / b[i];
      for (int j = 1; j <= n; j++)
        sum[j % h] += a[j];
      for (int j = 0; j < h; j++)
        if (sum[j] > max)
          max = sum[j];
    }
    cout << max;
}