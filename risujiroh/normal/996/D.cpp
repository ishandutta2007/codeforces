#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(2 * n); for (int i = 0; i < 2 * n; i++) cin >> a[i];
  VI f(n + 1);
  int t = 1;
  for (int i = 0; i < 2 * n; i++) {
    if (f[a[i]] == 0) {
      f[a[i]] = t;
      t++;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    a[i] = f[a[i]];
  }
  int res = 0;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      res += a[i] > a[j];
    }
  }
  cout << res << '\n';
  return 0;
}