#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) {
      swap(a, b);
    }
    int x = max(a, c - r);
    int y = min(b, c + r);
    cout << b - a - max(y - x, 0) << '\n';
  }
}