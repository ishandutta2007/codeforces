#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n; cin >> n;
  VI a(n); for (int i = 0; i < n; i++) cin >> a[i];
  VI t(n);
  for (int i = 0; i < n; i++) {
    t[i] = (a[i] - i + n - 1) / n * n + i;
  }
  int res = min_element(t.begin(), t.end()) - t.begin();
  cout << res + 1 << '\n';
  return 0;
}