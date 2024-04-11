#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<array<int, 5>> r(n);
    for (int i = 0; i < n; ++i)
      for (auto&& e : r[i]) cin >> e;
    auto winner = [&](int i, int j) -> int {
      int t = 0;
      for (int z : {0, 1, 2, 3, 4}) t += r[i][z] < r[j][z];
      return t >= 3 ? i : j;
    };
    int c = 0;
    for (int i = 1; i < n; ++i) c = winner(c, i);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (i == c) continue;
      ok &= winner(c, i) == c;
    }
    cout << (ok ? c + 1 : -1) << '\n';
  }
}