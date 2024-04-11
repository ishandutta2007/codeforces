#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<int, long long> up;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (up.count(x)) {
      up[x] = max(up[x], y - (long long) x * x);
    } else {
      up[x] = y - (long long) x * x;
    }
  }
  auto check = [&](pair<int, long long> a, pair<int, long long> b, pair<int, long long> c) {
    return (b.first - a.first) * (c.second - a.second) >= (c.first - a.first) * (b.second - a.second);
  };
  vector<pair<int, long long>> hull;
  for (auto p : up) {
    while ((int) hull.size() > 1 && check(hull[hull.size() - 2], hull[hull.size() - 1], p)) {
      hull.pop_back();
    }
    hull.push_back(p);
  }
  cout << hull.size() - 1 << "\n";
  return 0;
}