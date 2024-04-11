#include <bits/stdc++.h>

using namespace std;

signed main()
{
  int n, k;
  cin >> n >> k;
  string s, s1 = "";
  cin >> s;
  for (int i = 0; i < n; i++)
  {
    s1 += s[i];
    string res = "";
    for (int j = 0; j < k - 1; j++)
    {
      res += s1;
    }
    res += s;
    int schet = 0;
    
    for (int j = 0; j <= res.length() - n; j++)
    {
      bool flag = true;
      int a = 0;
      for (int m = j; m < j + n; m++)
      {
        if (res[m] != s[a])
        {
          
          flag = false;
          break;
        }
        a++;
      }
      if (flag)
      {
        schet++;
      }
      if (schet == k)
      {
        cout << res;
        return 0;
      }
    }
  }
  return 0;
}