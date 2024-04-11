#include <iostream>

using namespace std;

int main()
{
    int n, a[1001], max = 0, min = 0, kol = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 1; i < n; i++)
    {
      if (a[i] > a[max])
      {
        max = i;
        kol++;
      }
      if (a[i] < a[min])
      {
        min = i;
        kol++;
      }
    }
    cout << kol;
    return 0;
}