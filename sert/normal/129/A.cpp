#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, kol = 0, max, p, a[100002];
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      sum += a[i];
    sum = sum % 2;
    for (int i = 0; i < n; i++)
      a[i] = a[i] % 2;
    for (int i = 0; i < n; i++)
      if (sum == a[i])
        kol++;
    cout << kol << endl;
    return 0;

}