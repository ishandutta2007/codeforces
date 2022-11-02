#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main()
{
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; i++)
  {
    int x, y;
    cin >> y >> x;
    if (x % 2 == 0 and y % 2 == 0)
        cout << n*(y - 1) / 2 + n*(y - 1) % 2 + x / 2 << endl;
    else if (x % 2 == 1 and y % 2 == 0)
        cout << (n*(y - 1) / 2 + n*(y - 1) % 2 + x / 2 + n*n/2 + x % 2) << endl;      
    else if (x % 2 == 1 and y % 2 == 1)
        cout << n*(y - 1) / 2 + n*(y - 1) % 2 + x / 2 + x % 2 << endl;
    else
        cout <<n*(y - 1) / 2 + n*(y - 1) % 2 + x/ 2 + n*n/2 + n*n%2 << endl;
  }
  


  return 0;
}