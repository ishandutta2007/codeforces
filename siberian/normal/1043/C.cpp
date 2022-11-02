#include <bits/stdc++.h>
using namespace std;
//#define int long long
signed main() {

  string s;
  cin >> s;
  int n = s.length();
  vector <int> ans(n, 0);
  char start = s[0];
  char finish = s[0];
  for (int i = 1; i < n; i++)
  {
    if (start == 'b' && s[i] == 'b' && finish == 'a')
    {
      ans[i-1] = 1;
      start = 'a';
      finish = 'b';
    }
    else
    if (start == 'a' && s[i] == 'a' && finish == 'b')
    {
      ans[i-1] = 1;
      start = 'b';
      finish = 'a';
    }
    else
    finish = s[i];
  }
  if (s[n-1] == 'a')
  ans[n-1] = 1;
  for (auto i : ans)
  cout << i << " ";
  return 0;
}