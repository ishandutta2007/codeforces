#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  int cur = 0;
  bool neg = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ')') {
      --cur;
    } else {
      ++cur;
    }
    if (cur < 0) neg = true;
    if (neg) {
      ++ans;
    }
    if (cur >= 0) neg = false;
  }
  if (cur != 0) ans = -1;
  cout << ans << "\n";
}