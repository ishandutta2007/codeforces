#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int eight = 0;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '8') {
      ++eight;
    }
  }
  for (int i = eight; ~i; --i) {
    if (n >= i * 11) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}