#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    using i64 = long long;
    int n, m;
    cin >> n >> m;
    vector<pair<i64, i64>> a;
    while (n--) {
      i64 x;
      cin >> x;
      i64 c = 1;
      while (x % m == 0) {
        x /= m;
        c *= m;
      }
      if (empty(a) || a.back().first != x) {
        a.emplace_back(x, c);
      } else {
        a.back().second += c;
      }
    }
    cin >> n;
    vector<i64> b(n);
    for (i64& e : b) {
      cin >> e;
    }

    {
      i64 s = 0;
      for (auto [x, c] : a) {
        s += x * c;
      }
      for (i64 e : b) {
        s -= e;
      }
      if (s) {
        cout << "No\n";
        continue;
      }
    }

    [&] {
      while (!empty(b)) {
        if (b.back() % a.back().first) {
          cout << "No\n";
          return;
        }
        while (a.back().second < b.back() / a.back().first) {
          cout << "No\n";
          return;
        }
        i64 t = b.back() / a.back().first;
        {
          i64 t_ = t;
          while (t_ % m == 0) {
            t_ /= m;
          }
          if (1 < t_) {
            cout << "No\n";
            return;
          }
        }
        a.back().second -= t;
        if (a.back().second == 0) {
          a.pop_back();
        }
        b.pop_back();
      }
      cout << "Yes\n";
    }();
  }
}