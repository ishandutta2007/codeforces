#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  auto rec = [&](auto&& self, vector<int> a, int k) -> int {
    if (k == -1) {
      return 0;
    }
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += a[i] >> k & 1;
    }
    if (cnt == 0 or cnt == n) {
      return self(self, a, k - 1);
    }
    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
      if (a[i] >> k & 1) {
        x.push_back(a[i]);
      } else {
        y.push_back(a[i]);
      }
    }
    return min(self(self, x, k - 1), self(self, y, k - 1)) | 1 << k;
  };
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  cout << rec(rec, a, 29) << '\n';
}