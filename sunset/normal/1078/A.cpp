#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  long long x0, y0, x1, y1;
  scanf("%lld %lld %lld %lld", &x0, &y0, &x1, &y1);
  auto get = [&](long long a, long long b, long long c, long long x, long long y) {
    vector<pair<double, double>> result;
    if (a) {
      result.emplace_back(-(double)(b * y + c) / a, y);
    }
    if (b) {
      result.emplace_back(x, -(double)(a * x + c) / b);
    }
    return result;
  };
  vector<pair<double, double>> p0 = get(a, b, c, x0, y0);
  vector<pair<double, double>> p1 = get(a, b, c, x1, y1);
  double answer = abs(x1 - x0) + abs(y1 - y0);
  for (auto q0 : p0) {
    for (auto q1 : p1) {
      double dist0 = abs(x0 - q0.first) + abs(y0 - q0.second);
      double dist1 = abs(x1 - q1.first) + abs(y1 - q1.second);
      double dist2 = sqrt((q0.first - q1.first) * (q0.first - q1.first) + (q0.second - q1.second) * (q0.second - q1.second));
      answer = min(answer, dist0 + dist1 + dist2);
    }
  }
  printf("%.9lf\n", answer);
  return 0;
}