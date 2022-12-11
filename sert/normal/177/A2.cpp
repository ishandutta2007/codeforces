#include <iostream>

using namespace std;

int main()
{
    int k;
    int sum = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        cin >> k;
        if (i == j || i + j == n - 1 || i == n / 2 || j == n / 2)
          sum += k;
      }
    cout << sum;
}