#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VI c(n); for (int i = 0; i < n; i++) cin >> c[i];
  VI a(m); for (int i = 0; i < m; i++) cin >> a[i];

  int p = 0, res = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] <= a[p]) {
      res++;
      p++;
    }
    if (p == m) break;
  }
  cout << res << '\n';
  return 0;
}