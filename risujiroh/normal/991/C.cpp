#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  lint n; cin >> n;

  auto f = [&](lint k) {
    lint c = n, v = 0;
    while (true) {
      if (c >= k) {
        c -= k;
        v += k;
      } else if (c > 0) {
        v += c;
        c = 0;
        break;
      } else {
        break;
      }
      c -= c / 10;
    }
    return 2 * v >= n;
  };

  lint l = 0, r = n;
  while (r - l > 1) {
    lint m = (l + r) / 2;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
  return 0;
}