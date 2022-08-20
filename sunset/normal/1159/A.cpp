#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  reverse(s.begin(), s.end());
  int ans = 0;
  int cur = 0;
  for (auto c : s) {
    if (c == '+') {
      ans = max(ans, ++cur);
    } else {
      --cur;
    }
  }
  cout << ans << "\n";
  return 0;
}