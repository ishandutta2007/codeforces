#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define FAST ios_base::sync_with_stdio(false); \
			       cin.tie(nullptr);                 \
	           cout.tie(nullptr)


signed main() {
  
  FAST;
  int n;
  pair <int, int> a, b, c;
  cin >> n;
  cin >> a.first >> a.second;
  a.first--;
  a.second--;
  cin >> b.first >> b.second;
  cin >> c.first >> c.second;
  b.first--;
  b.second--;
  c.first--;
  c.second--;
  if (max(b.first, c.first) >= a.first && min(b.first, c.first) <= a.first)
  {
    cout << "NO\n";
    return 0;
  }
  else if (max(b.second, c.second) >= a.second && min(b.second, c.second) <= a.second)
  {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  return 0;
}