#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#ifdef SERT
  bool D = true;
#else
  bool D = false;
#endif

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || a + b + 2 > n) {
    cout << "-1\n";
    return;
  }
  int dd = (a > b ? 1 : -1);
  vector<int> v = {0};
  int mn = 0;
  int mx = 0;
  for (int i = 0; i <= a + b; i++) {
    v.push_back(dd == 1 ? ++mx : --mn);
    dd = -dd;
  }
  for (int i = a + b + 2; i < n; i++)
    v.push_back(v.back() - dd);
  mn = *min_element(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i] + 1 - mn << " ";
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