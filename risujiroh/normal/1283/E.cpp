#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> x(n), c(n + 2);
  for (auto&& e : x) {
    cin >> e;
    ++c[e];
  }
  sort(begin(x), end(x));
  {
    vector<int> a(n + 2);
    for (int i = 0; i < n + 2; ++i) {
      if (c[i]) {
        for (int j = i; j < min(i + 3, n + 2); ++j) {
          c[j] = 0;
        }
        a[i + 1] = 1;
      }
    }
    int res = accumulate(begin(a), end(a), 0);
    cout << res << ' ';
  }
  {
    vector<int> a(n + 2);
    for (int e : x) {
      for (int y : {e - 1, e, e + 1}) {
        if (a[y] == 0) {
          a[y] = 1;
          break;
        }
      }
    }
    int res = accumulate(begin(a), end(a), 0);
    cout << res << '\n';
  }
}