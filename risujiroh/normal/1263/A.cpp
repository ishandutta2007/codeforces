#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int r, g, b;
    cin >> r >> g >> b;
    int res = (r + g + b) / 2;
    res = min({res, r + g, r + b, g + b});
    cout << res << '\n';
  }
}