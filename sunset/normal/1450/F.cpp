#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    vector<pair<int, int>> intervals;
    for (int i = 0, j = 0; i < n; ++i) {
      if (i == n - 1 || a[i] == a[i + 1]) {
        intervals.emplace_back(j, i);
        j = i + 1;
      }
    }
    vector<int> appear(n);
    for (auto p : intervals) {
      appear[a[p.first]]++;
      appear[a[p.second]]++;
    }
    int p = max_element(appear.begin(), appear.end()) - appear.begin();
    if (appear[p] <= (int) intervals.size() + 1) {
      cout << (int) intervals.size() - 1 << "\n";
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] != a[i + 1] && a[i] != p && a[i + 1] != p) {
        cnt++;
      }
    }
    if (appear[p] > (int) intervals.size() + cnt + 1) {
      cout << -1 << "\n";
    } else {
      cout << appear[p] - 2 << "\n";
    }
  }
  // two side > ceil((block - one side) / 2)
  return 0;
}