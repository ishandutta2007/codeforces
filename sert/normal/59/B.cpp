#include <iostream>

using namespace std;

int main()
{
    int k, n, sum = 0, mn = 100500, kol = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> k;
      if (k % 2 == 1 && k < mn)
        mn = k;
      if (k % 2 == 1)
        kol++;
      sum += k;
    }
    if (mn % 2 == 0)
      cout << "0";
    else
      if (kol % 2 == 0)
        cout << sum - mn;
      else
        cout << sum;
    return 0;
}