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
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
      int a;
      cin >> a;
      ++mp[a];
    }
    int one = 0;
    int two = 0;
    for (auto [_, e] : mp) {
      ++(e == 1 ? one : two);
    }
    cout << (2 * two + one + (0 < one)) / 2 << '\n';
  }
}