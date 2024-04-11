#include <bits/stdc++.h>

using namespace std;

template <class C> constexpr int len(const C& c) { return int(c.size()); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a & 1) {
        pos.push_back(i);
      }
    }

    constexpr auto inf = numeric_limits<int64_t>::max() / 2;
    int64_t ans = inf;

    for (int init : {0, 1}) {
      vector<int> v;
      for (int i = init; i < n; i += 2) {
        v.push_back(i);
      }
      if (len(v) == len(pos)) {
        int64_t cur = 0;
        for (int i = 0; i < len(pos); ++i) {
          cur += abs(pos[i] - v[i]);
        }
        ans = min(ans, cur);
      }
    }

    if (ans < inf) {
      cout << ans << '\n';
    } else {
      cout << "-1\n";
    }
  }
}