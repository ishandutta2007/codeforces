#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, max, p, a[100002];
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    max = 1;
    for (int i = 0; i < n; i++)
      if (a[i] > a[max])
        max = i;
    if (a[max] == 1)
      a[max] = 2;
    else
      a[max] = 1;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    return 0;

}