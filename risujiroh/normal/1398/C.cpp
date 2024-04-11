#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<int, int> mp;
    auto res = 0LL;
    int sum = 0;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      int a = (c - '0') - 1;
      sum += a;
      res += mp[sum];
      ++mp[sum];
    }
    cout << res << '\n';
  }
}