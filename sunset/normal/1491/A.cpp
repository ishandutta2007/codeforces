#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int p;
      cin >> p;
      --p;
      s -= a[p];
      a[p] ^= 1;
      s += a[p];
    } else {
      int k;
      cin >> k;
      cout << (k <= s) << "\n";
    }
  }
  return 0;
}