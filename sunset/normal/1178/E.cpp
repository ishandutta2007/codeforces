#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string pre, suf;
  for (int i = 0, j = (int) s.size() - 1; i <= j; i += 2, j -= 2) {
    if (j - i < 3) {
      pre.push_back(s[j]);
    } else {
      for (char c = 'a'; c <= 'c'; ++c) {
        int cnt = (s[i] == c) + (s[i + 1] == c) + (s[j - 1] == c) + (s[j] == c);
        if (cnt >= 2) {
          pre.push_back(c);
          suf.push_back(c);
          break;
        }
      }
    }
  }
  reverse(suf.begin(), suf.end());
  cout << pre + suf << "\n";
  return 0;
}