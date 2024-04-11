#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int _t = 0; _t < T; ++_t) {
    bool bad = false;
    int n, m;
    cin >> n >> m;
    int ml = m, mh = m;
    int mt = 0;
    for (int i = 0; i < n; ++i) {
      int t, l, h;
      cin >> t >> l >> h;
      mh += t - mt;
      ml -= t - mt;
      ml = max(ml, l);
      mh = min(mh, h);
      if (mh < ml) {
        bad = true;
      }
      mt = t;
    }
    if (bad) cout << "NO\n";
    else cout << "YES\n";
  }
}