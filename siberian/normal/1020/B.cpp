#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;

signed main()
{
  int n;
  cin >> n;
  vector <int> a;
  int c;
  for(int i = 0; i < n; i++)
  {
    cin >> c;
    a.push_back(c-1);
  }
  vector <bool> used;
  for (int i = 0; i < n; i++)
  {
    used.assign(n,false);
    used[i] = true;
    int pos = i;
    while (true)
    { 
      pos = a[pos];
      if (used[pos])
      {
        cout << pos + 1 << " ";
        break;
      }
      used[pos] = true;
    }
  }
  return 0;
}