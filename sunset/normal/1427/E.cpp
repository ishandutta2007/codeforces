#include <bits/stdc++.h>

using namespace std;

const int L = 60;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  srand(time(0));
  vector<long long> linear_base(L);
  vector<tuple<long long, char, long long>> ans;
  set<long long> s;
  auto add = [&](long long x, long long y, int type) {
    if (!type) {
      if (s.find(x + y) == s.end()) {
        ans.emplace_back(x, '+', y);
        s.insert(x + y);
      }
    } else {
      if (s.find(x ^ y) == s.end()) {
        ans.emplace_back(x, '^', y);
        s.insert(x ^ y);
      }
    }
  };
  auto extend = [&](long long v) {
    for (int i = L - 1; ~i; --i) {
      if (v >> i & 1) {
        if (linear_base[i]) {
          add(v, linear_base[i], 1);
          v ^= linear_base[i];
        } else {
          linear_base[i] = v;
          for (int j = L - 1; j > i; --j) {
            if (linear_base[j] >> i & 1) {
              add(v, linear_base[j], 1);
              linear_base[j] ^= v;
            }
          }
          break;
        }
      }
    }
  };
  int x;
  cin >> x;
  extend(x);
  while (s.find(1) == s.end()) {
    int foo, bar;
    do {
      foo = rand() % L;
      bar = rand() % L;
    } while (!linear_base[foo] || !linear_base[bar]);
    add(linear_base[foo], linear_base[bar], 0);
    extend(linear_base[foo] + linear_base[bar]);
  }
  cout << ans.size() << "\n";
  for (auto p : ans) {
    cout << get<0>(p) << " " << get<1>(p) << " " << get<2>(p) << "\n";
  }
  return 0;
}