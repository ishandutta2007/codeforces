#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k, n, b[101], c[101];
    char a;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
      cin >> a;
      k = int(a);
      if (i < n) b[i] = k; else c[i - n] = k;
    }
    if (n == 1 && b[0] == c[0]) {cout << "NO"; return 0;}
    sort(b, b + n);
    sort(c, c + n);
    for (int i = 1; i < n; i++)
      if ((b[i] - c[i]) * (b[i - 1] - c[i - 1]) <= 0)
      {
        cout << "NO" << endl;
        //cout << b[i] << " " << c[i] << " " << b[i - 1] << " " << c[i - 1];
        return 0;
      }

    cout << "YES";

    return 0;
}