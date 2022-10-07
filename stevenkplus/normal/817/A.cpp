// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

// =========== Book ============ //

// =========== Solution ============= //

int main()  {
  int x1, y1, x2, y2, x, y;
  cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
  x1 -= x2;
  y1 -= y2;
  if (x1 % x != 0 || y1 % y != 0) cout << "NO\n";
  else if ((x1 / x + y1 / y) % 2 != 0) cout << "NO\n";
  else cout << "YES\n";
}