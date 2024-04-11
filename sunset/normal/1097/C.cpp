#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int ans = 0;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int foo = 0;
    int bar = 0;
    for (auto c : s) {
      if (c == '(') {
        ++foo;
      } else {
        if (foo) {
          --foo;
        } else {
          ++bar;
        }
      }
    }
    if (foo && bar) {
      continue;
    }
    if (cnt[bar - foo]) {
      ++ans;
      --cnt[bar - foo];
    } else {
      ++cnt[foo - bar];
    }
  }
  cout << ans << "\n";
  return 0;
}