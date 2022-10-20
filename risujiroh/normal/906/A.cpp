#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int res = 0;
  vector<int> a(26, 1);
  while (n--) {
    char t;
    string s;
    cin >> t >> s;
    if (t == '.') {
      for (char c : s) {
        a[c - 'a'] = 0;
      }
    } else if (t == '!') {
      if (count(begin(a), end(a), 1) == 1) {
        ++res;
      }
      for (char c = 'a'; c <= 'z'; ++c) {
        if (s.find(c) == string::npos) {
          a[c - 'a'] = 0;
        }
      }
    } else {
      res += count(begin(a), end(a), 1) == 1 and n;
      a[s[0] - 'a'] = 0;
    }
  }
  cout << res << '\n';
}