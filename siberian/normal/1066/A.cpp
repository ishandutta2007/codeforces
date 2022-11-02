#include <bits/stdc++.h>
using namespace std;

signed main()
{
  int t;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int L, v, li, ri;
    cin >> L >> v >> li >> ri;
    int ans = L / v;
    int col  = ri/v - li/v;
    if (li % v == 0)
    {
      col += 1;
    }
    ans -= col;
    cout << ans << endl;
  }
  return 0;
}