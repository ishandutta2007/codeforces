#include <bits/stdc++.h>

using namespace std;

const string s = "codeforces";

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  pair<int, pair<int, int>> ans(1e9, make_pair(-1, -1));
  for (int i = 1; i <= 50; ++i) {
    for (int j = 1; j <= 10; ++j) {
      long long res = 1;
      for (int k = 1; k <= j; ++k) {
        res *= i;
      }
      for (int k = 1; k <= 10 - j; ++k) {
        res *= i - 1;
      }
      if (res >= n) {
        ans = min(ans, make_pair((i - 1) * 10 + j, make_pair(i, j)));
      }
    }
  }
  int foo = ans.second.first, bar = ans.second.second;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < (i < bar ? foo : foo - 1); ++j) {
      cout << s[i];
    }
  }
  cout << "\n";
  return 0;
}