#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  auto check = [&](int m) -> bool {
    vector small(begin(a), begin(a) + m);
    vector large(end(a) - (m + 1), end(a));
    for (int i = 0; i < m; ++i) {
      if (not(large[i] > small[i] and small[i] < large[i + 1])) return false;
    }
    return true;
  };
  int ok = 0, ng = (n - 1) / 2 + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
  vector<int> ans;
  ans.reserve(n);
  {
    vector small(begin(a), begin(a) + ok);
    vector large(end(a) - (ok + 1), end(a));
    for (int i = 0; i <= ok; ++i) {
      ans.push_back(large[i]);
      if (i == ok) break;
      ans.push_back(small[i]);
    }
    ans.insert(end(ans), begin(a) + ok, end(a) - (ok + 1));
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}