#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  vector<array<int, 2>> ans;

  int m = (n - 1) / 3;

  for (int i = 0; i < m; ++i) {
    ans.push_back({i, m - i - 1});
  }

  for (int i = 0; i <= m; ++i) {
    ans.push_back({i, m - i});
    ans.back()[0] += m;
    ans.back()[1] += m;
  }

  if (n % 3 == 0) {
    ans.push_back({n / 3 * 2 - 1, n / 3 * 2 - 1});
  }

  cout << size(ans) << '\n';
  for (auto [i, j] : ans) {
    cout << i + 1 << ' ' << j + 1 << '\n';
  }
}