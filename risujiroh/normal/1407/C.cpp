#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;

  auto query = [&](int i, int j) -> int {
    assert(0 <= i), assert(i < n);
    assert(0 <= j), assert(j < n);
    assert(i != j);
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
  };

  vector<int> idx(n), ans(n);
  iota(begin(idx), end(idx), 0);
  while (size(idx) > 1) {
    int i = idx[size(idx) - 2], j = idx.back();
    int x = query(i, j);
    int y = query(j, i);
    assert(x != y);
    if (x > y) {
      ans[i] = x;
      idx.erase(find(begin(idx), end(idx), i));
    } else {
      ans[j] = y;
      idx.erase(find(begin(idx), end(idx), j));
    }
  }
  ans[idx[0]] = 1;
  while (count(begin(ans), end(ans), ans[idx[0]]) > 1) ++ans[idx[0]];

  cout << '!';
  for (auto&& e : ans) cout << ' ' << e;
  cout << endl;
}