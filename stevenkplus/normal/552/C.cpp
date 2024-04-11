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
  ll w, m;
  cin >> w >> m;
  ll cur = 1;
  while (cur < m) cur *= w;
  while (cur) {
    m = min(m, abs(m - cur));
    cur /= w;
  }
  if (m == 0) cout << "YES\n";
  else cout << "NO\n";
}