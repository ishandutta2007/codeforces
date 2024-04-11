#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  VI b(n); for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 or b[i] == 1) return cout << -1 << '\n', 0;
  }
  b.push_back(b[0]);
  b.erase(b.begin());
  double res = m;
  for (int i = n - 1; i >= 0; i--) {
    res *= b[i] / (b[i] - 1.0);
    res *= a[i] / (a[i] - 1.0);
  }
  cout << fixed << setprecision(10) << res - m << '\n';
  return 0;
}