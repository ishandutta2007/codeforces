#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& e : a) cin >> e;
  vector<int> last(n, -1);

  using i64 = long long;

  i64 ans = accumulate(begin(a), end(a), 0ll);

  int b = -1;
  int b_last = -1;

  for (int t : views::iota(0, q)) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int i, x;
      cin >> i >> x;
      --i;
      ans -= last[i] < b_last ? b : a[i];
      a[i] = x;
      last[i] = t;
      ans += a[i];
    } else {
      int x;
      cin >> x;
      b = x;
      b_last = t;
      ans = i64(x) * n;
    }
    cout << ans << '\n';
  }
}