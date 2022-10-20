#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> mp;
    int x = 0, y = 0, mn = inf;
    mp[{x, y}] = 0;
    string res = "-1";
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') --x;
      if (s[i] == 'R') ++x;
      if (s[i] == 'U') ++y;
      if (s[i] == 'D') --y;
      if (mp.count({x, y}) and i - mp[{x, y}] < mn) {
        mn = i - mp[{x, y}];
        res = to_string(i - mn + 1) + " " + to_string(i + 1);
      }
      mp[{x, y}] = i + 1;
    }
    cout << res << '\n';
  }
}