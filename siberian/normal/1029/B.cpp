#include <bits/stdc++.h>

using namespace std;

signed main()
{
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  if (n == 1)
  {
    cout << 1;
    return 0;
  }
  int ans = 1;
  int schet = 1;
  for (int i = 1; i < n; i++)
  {
    int l = a[i - 1];
    int r = a[i];
    if (l * 2 >= r)
    {
      schet++;
    }   
    else
    {
      ans = max(ans, schet);
      schet = 1;
    }
  }
  ans = max(ans, schet);
  cout << ans;
  return 0;
}