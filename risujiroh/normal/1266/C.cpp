#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  if (h == 1 and w == 1) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int x = i + 1;
      int y = h + j + 1;
      if (h > w) {
        x = j + 1;
        y = w + i + 1;
      }
      cout << lcm(x, y) << " \n"[j == w - 1];
    }
  }
}