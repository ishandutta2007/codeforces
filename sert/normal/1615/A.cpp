#include <bits/stdc++.h>
using namespace std;

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif
using ll = long long;

void solve() {
  int n, x;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    sum += x;
  }
  cout << !!(sum % n) << "\n";
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