#include <bits/stdc++.h>

using namespace std;


signed main()
{
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> m;
    string s;
    cin >> s;
    bool flag = true;
    for (int j = 0; j < m/2; j++)
    {
      if (abs(s[j] - s[m - j - 1]) == 1 || abs(s[j] - s[m - j - 1]) > 2)
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }


  return 0;
}