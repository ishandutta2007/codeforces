#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  vector<pair<int, int>> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  set<pair<int, int>> s;
  for (int i = 0; i < 3; ++i) {
    for (int j = min(a[i].second, a[(i + 1) % 3].second); j <= max(a[i].second, a[(i + 1) % 3].second); ++j) {
      s.insert(make_pair(a[1].first, j));
    }
  }
  for (int i = a[0].first; i <= a[1].first; ++i) {
    s.insert(make_pair(i, a[0].second));
  }
  for (int i = a[1].first; i <= a[2].first; ++i) {
    s.insert(make_pair(i, a[2].second));
  }
  printf("%d\n", s.size());
  for (auto p : s) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}