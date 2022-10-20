#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (size(s) == 2) {
      cout << s[1] << '\n';
    } else {
      cout << *min_element(begin(s), end(s)) << '\n';
    }
  }
}