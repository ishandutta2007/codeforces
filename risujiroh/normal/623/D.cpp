#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct stopwatch {
  clock_t t = clock();
  void restart() { t = clock(); }
  int elapsed() const { return (clock() - t) * 1000 / CLOCKS_PER_SEC; }
  void operator()(string s = "Time") const {
    cerr << s + ": " << elapsed() << " ms\n";
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  using ld = long double;
  int n;
  cin >> n;
  vector<ld> q(n);
  for (auto&& e : q) {
    int p;
    cin >> p;
    e = 1 - 0.01L * p;
  }
  ld res = n, prod = 1;
  priority_queue<pair<ld, int>> pq;
  auto a = q;
  for (int i = 0; i < n; ++i) {
    prod *= 1 - q[i];
    pq.emplace((1 - q[i] * q[i]) / (1 - q[i]), i);
  }
  for (stopwatch sw; sw.elapsed() < 1800; ) {
    res += 1 - prod;
    auto [mx, i] = pq.top();
    pq.pop();
    prod /= 1 - a[i];
    a[i] *= q[i];
    prod *= 1 - a[i];
    pq.emplace((1 - a[i] * q[i]) / (1 - a[i]), i);
  }
  cout << res << '\n';
}