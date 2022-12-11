#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[101];
    cin >> n;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      tot += a[i];
    }
    sort(a, a + n);
    int sum = 0;
    int i = n;
    while (sum <= tot - sum)
    {
      i--;
      sum += a[i];
    }
    cout << (n - i);
    return 0;
}