#include <bits/stdc++.h>

using namespace std;

template <class C> constexpr int len(const C& c) { return int(c.size()); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int c, d;
    cin >> c >> d;
    if (d < c) {
      swap(c, d);
    }
    if ((d - c) % 2) {
      cout << "-1\n";
    } else if (c == 0 && d == 0) {
      cout << "0\n";
    } else if (c == d) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}