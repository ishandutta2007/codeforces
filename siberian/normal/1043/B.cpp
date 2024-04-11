#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin>>n;
  vector <int> a1(n+1, 0);
  vector <int> a(n, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> a1[i];
    a[i-1] = a1[i] - a1[i-1];
   // cout << a[i] <<" " << a1[i] << " " << a1[i-1]<< endl;
  }

  vector <int> ans;
 // for (auto i : a)
 // cout << i << " ";
 // cout << endl;

  for (int i = 1; i <= n; i++)
  {
    bool flag = false;
    for (int j = 0; j < n; j++)
    {
      if (a[j % i] != a[j])
      flag = true;
    }
    if (!flag)
    ans.push_back(i);
  }

  cout << ans.size() << endl;
  for (auto i : ans)
  cout << i << " ";
  return 0;
}