#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  vector<long long> x(1), y(1);
  cin >> x[0] >> y[0];
  long long ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  while (x.back() < 3e16 and y.back() < 3e16) {
    x.push_back(ax * x.back() + bx);
    y.push_back(ay * y.back() + by);
  }
  int n = x.size();
  long long xs, ys, t;
  cin >> xs >> ys >> t;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (abs(x[i] - xs) + abs(y[i] - ys) + abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t) {
        res = max(res, abs(j - i) + 1);
      }
    }
  }
  cout << res << '\n';
}