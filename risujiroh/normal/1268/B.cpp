#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (i & 1) {
      x += a / 2;
      y += a - a / 2;
    } else {
      x += a - a / 2;
      y += a / 2;
    }
  }
  cout << min(x, y) << '\n';
}