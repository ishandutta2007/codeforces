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
  int l = 0;
  int r = s.size() - 1;
  while (true) {
    if (s[l] != s[r]) {
      cout << 0 << "\n";
      return 0;
    }
    int ll = l;
    while (ll < (int) s.size() && s[ll] == s[l]) {
      ++ll;
    }
    int rr = r;
    while (rr >= 0 && s[rr] == s[r]) {
      --rr;
    }
    if (ll == l + 1 && rr == r - 1) {
      cout << 0 << "\n";
      return 0;
    }
    if (ll > r) {
      cout << r - l + 2 << "\n";
      return 0;
    } else {
      l = ll;
      r = rr;
    }
  }
  return 0;
}