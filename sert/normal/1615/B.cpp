#include <bits/stdc++.h>
using namespace std;

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif
using ll = long long;

int go(int n, int b) {
  int x = (1 << b);
  int ans = (n / (x * 2)) * x;
  n %= (x * 2);
  return ans + max(0, n - x + 1);
}

void solve() {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  for (int b = 0; (1 << b) <= r; b++) {
    int x = go(r, b);
    int y = go(l - 1, b);
    //cout << l << " " << r << " " << b << " " << x << " " << y << endl;
    ans = max(ans, x - y);
  }
  cout << (r - l + 1) - ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 3;
  }
  cin >> t;
  while (t--) {
    solve();
  }
}