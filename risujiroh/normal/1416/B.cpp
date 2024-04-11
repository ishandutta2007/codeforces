#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (accumulate(begin(a), end(a), 0) % n) {
      cout << "-1\n";
      continue;
    }

    vector<array<int, 3>> ans;
    auto op = [&](int i, int j, int val) -> void {
      assert(val % i == 0);
      assert(a[i] >= val);
      int x = val / i;
      ans.push_back({i, j, x});
      a[i] -= val;
      a[j] += val;
    };

    for (int i = 2; i <= n; ++i) {
      assert(a[1] >= i - 1);
      if (a[i] % i) {
        int need = i - a[i] % i;
        op(1, i, need);
      }
      op(i, 1, a[i]);
    }
    int v = accumulate(begin(a), end(a), 0) / n;
    for (int i = 2; i <= n; ++i) op(1, i, v);
    cout << size(ans) << '\n';
    for (auto [i, j, x] : ans) cout << i << ' ' << j << ' ' << x << '\n';
  }
}