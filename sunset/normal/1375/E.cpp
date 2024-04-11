#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) { return make_pair(a[x], x) < make_pair(a[y], y); });
  for (int i = 0; i < n; ++i) {
    a[ord[i]] = i;
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    vector<int> pos;
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) {
        pos.push_back(j);
      }
    }
    sort(pos.begin(), pos.end(), [&](int x, int y) { return a[x] > a[y]; });
    for (int j : pos) {
      swap(a[i], a[j]);
      ans.emplace_back(i, j);
    }
  }
  cout << ans.size() << "\n";
  for (auto p : ans) {
    cout << p.first + 1 << " " << p.second + 1 << "\n";
  }
  return 0;
}