#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n;
  cin>>n;
  int k = 0;
  int sum = 0;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
    k = max(a[i], k);
  }
  
  while (true)
  {
    if(k*n-sum > sum)
    {
      cout << k << endl;
      return 0;
    }
    k++;
  }

  return 0;
}