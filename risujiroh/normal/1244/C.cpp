#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long n, p, w, d;
  cin >> n >> p >> w >> d;
  for (int y = 0; y < w; ++y) {
    if ((p - d * y) % w) {
      continue;
    }
    long long x = (p - d * y) / w;
    if (x < 0 or x > n) {
      continue;
    }
    if (y > n) {
      continue;
    }
    long long z = n - x - y;
    if (z < 0 or z > n) {
      continue;
    }
    cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
  }
  cout << "-1\n";
}