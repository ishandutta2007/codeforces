#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 300;

int main() {
  cout << string(lim, 'a') << endl;
  int x;
  cin >> x;
  if (x == 0) {
    return 0;
  }
  x = lim - x;
  cout << string(lim, 'b') << endl;
  int y;
  cin >> y;
  if (y == 0) {
    return 0;
  }
  y = lim - y;
  int n = x + y;
  if (x == 0 or y == 0) {
    cout << string(n, x ? 'a' : 'b') << endl;
    int d;
    cin >> d;
    assert(d == 0);
    return 0;
  }
  string s(x, 'a');
  for (int k = 0; k <= x; ) {
    int c = 0;
    for (int i = 0; i <= (int)s.size(); ++i) {
      if (c == k) {
        cout << s.substr(0, i) + "b" + s.substr(i) << endl;
        int d;
        cin >> d;
        if (d == 0) {
          return 0;
        }
        if (d == n - (int)s.size() - 1) {
          s = s.substr(0, i) + "b" + s.substr(i);
        } else {
          ++k;
        }
        break;
      }
      c += s[i] == 'a';
    }
  }
}