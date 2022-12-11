#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << 34 + i << " ";
  }
  cout << "\n";
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