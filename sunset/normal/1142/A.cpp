#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  long long x = (long long) n * k, y = 1;
  auto solve = [&](long long l) {
    l %= k;
    if (!l) {
      l = k;
    }
    for (int i = 0; i < n; ++i) {
      long long step = (long long) n * k / __gcd(l, (long long) n * k);
      x = min(x, step);
      y = max(y, step);
      l += k;
    }
  };
  solve(a + b);
  solve((k - a) + b);
  solve(a + (k - b));
  solve((k - a) + (k - b));
  cout << x << " " << y << "\n";
  return 0;
}