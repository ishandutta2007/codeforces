#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n), b(n);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  vector<int> order;
  for (int i = 0; i < n; ++i)
    if (b[i]) order.push_back(i);
  sort(begin(order), end(order), [&](int i, int j) { return a[i] < a[j]; });
  int sum = accumulate(begin(a), end(a), 0);
  r = min(r, sum);
  auto check = [&](int m) -> bool {
    int x = 0;
    for (int z = 0; z < m - 1; ++z) x += a[order[z]];
    if (x > r - l) return false;
    bitset<10001> bs;
    bs[0] = 1;
    for (int z = m - 1; z < int(size(order)); ++z) bs |= bs << a[order[z]];
    bs[0] = 0;
    for (int i = 0; i < n; ++i)
      if (b[i] == 0) bs |= bs << a[i];
    return int(bs._Find_next(sum - r - 1)) <= sum - l - x;
  };
  int ok = 0, ng = size(order) + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}