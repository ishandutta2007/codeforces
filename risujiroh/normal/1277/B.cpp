#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
      int a;
      cin >> a;
      int tz = __builtin_ctz(a);
      mp[a >> tz] = max(mp[a >> tz], tz);
    }
    int res = 0;
    for (auto e : mp) {
      res += e.second;
    }
    cout << res << '\n';
  }
}