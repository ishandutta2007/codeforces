#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    using i64 = long long;

    int n;
    i64 a, b;
    cin >> n >> a >> b;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i];

    i64 cur = (a + b) * x[n];
    i64 ans = cur;
    for (int i = n; i--;) {
      cur -= (a + b) * (x[i + 1] - x[i]);
      cur += b * (x[i + 1] - x[i]) * (n - i);
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}