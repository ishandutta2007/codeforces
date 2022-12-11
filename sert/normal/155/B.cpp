#include <iostream>

using namespace std;

int main()
{
  int a[1001], b[1001], n, k, kol = 1, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if ((b[j] < b[j + 1]) || ((b[j] == b[j + 1]) && (a[j] < a[j + 1])))
      {
        swap(b[j], b[j + 1]);
        swap(a[j], a[j + 1]);
      }
  for (int i = 0; i < n; i++)
  {
    sum = sum + a[i];
    kol = kol + b[i] - 1;
    if (kol == 0)
    {
      cout << sum;
      return 0;
    }
  }
  cout << sum;
  return 0;
}