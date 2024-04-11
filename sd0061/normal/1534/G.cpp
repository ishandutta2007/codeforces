#include <bits/stdc++.h>
using int64 = long long;

const int N = 800005;

int n;
std::pair<int, int> a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = std::make_pair(x + y, x - y);
  }
  std::sort(a, a + n);
  std::priority_queue<int64> down;
  std::priority_queue<int64, std::vector<int64>, std::greater<int64>> up;
  int64 K = 1, B = -a[0].second, lazy_down = 0, lazy_up = 0;
  down.push(a[0].second);
  up.push(a[0].second);

  for (int i = 1; i < n; ++i) {
    int delta = a[i].first - a[i - 1].first;
    lazy_down -= delta;
    lazy_up += delta;
    B -= delta * K;

    K += 1;
    B -= a[i].second;
    if (a[i].second <= down.top() + lazy_down) {
      down.push(a[i].second - lazy_down);
      down.push(a[i].second - lazy_down);
      up.push(down.top() + lazy_down - lazy_up);
      down.pop();
    } else {
      up.push(a[i].second - lazy_up);
      up.push(a[i].second - lazy_up);
      down.push(up.top() + lazy_up - lazy_down);
      up.pop();
    }
  }
  std::vector<int64> v;
  while (!up.empty()) {
    v.emplace_back(up.top() + lazy_up);
    up.pop();
  }
  int64 res = K * v.back() + B;
  int64 last = v.back();
  v.pop_back();
  while (!v.empty()) {
    --K;
    res -= K * (last - v.back());
    last = v.back();
    v.pop_back();
  }
  std::cout << res / 2 << std::endl;
  return 0;
}