#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a), greater{});
  vector<int> ans;
  ans.reserve(n);
  for (int i = 0; i < n; ++i) {
    int j = n - i - 1;
    if (i > j) break;
    ans.push_back(a[i]);
    if (i < j) ans.push_back(a[j]);
  }
  cout << (n - 1) / 2 << '\n';
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}