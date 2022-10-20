#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& e : a) {
    cin >> e;
  }

  using i64 = long long;

  i64 ans = numeric_limits<i64>::max();

  for (int x = 0; x < n; ++x) {
    i64 cur = 0;
    {
      i64 prv = 0;
      for (int i = x + 1; i < n; ++i) {
        i64 t = prv / a[i] + 1;
        cur += t;
        prv = a[i] * t;
      }
    }
    {
      i64 prv = 0;
      for (int i = x - 1; 0 <= i; --i) {
        i64 t = prv / a[i] + 1;
        cur += t;
        prv = a[i] * t;
      }
    }
    ans = min(ans, cur);
  }

  cout << ans << '\n';
}