#include <bits/stdc++.h>

using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			       cin.tie(nullptr);                 \
	           cout.tie(nullptr)

#define int long long


signed main() {
  
  FAST;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    if (a - b > 1)
    {
      cout << "NO\n";
      continue;
    }
    a += b;
    bool flag = true;
    for (int i = 2; i * i <= a; i++)
    {
      if (a % i == 0)
      {
        cout << "NO\n";
        flag = false;
        break;
      }
    }
    if (flag)
    {
      cout << "YES\n";
    }
  }
  return 0;
}