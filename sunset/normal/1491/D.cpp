#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      cout << "NO" << "\n";
      continue;
    }
    bool bad = false;
    int s = 0;
    for (int i = 0; i < 30; ++i) {
      if (u >> i & 1) {
        s++;
      }
      if (v >> i & 1) {
        s--;
      }
      if (s < 0) {
        bad = true;
      }
    }
    cout << (bad ? "NO" : "YES") << "\n";
  }
  return 0;
}