#include <bits/stdc++.h>

const int max_N = (int) 1e5 + 21;

int n, q, last_m, last_a[max_N], max_a;

std::deque<int> dq;

std::pair<int, int> ans[max_N];

void init() {
  while (dq.front() != max_a) {
    int a = dq.front();
    dq.pop_front();
    int b = dq.front();
    dq.pop_front();
    ans[++last_m] = {a, b};
    if (a < b) {
      std::swap(a, b);
    }
    dq.push_front(a);
    dq.push_back(b);
  }
  for (int i = 1; i <= n; ++i) {
    last_a[i] = dq.front();
    dq.pop_front();
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    dq.push_back(a);
    max_a = std::max(max_a, a);
  }
  init();
  while (q--) {
    long long m;
    scanf("%lld", &m);
    if (m <= last_m) {
      printf("%d %d\n", ans[m].first, ans[m].second);
    } else {
      int x = (m - last_m - 1) % (n - 1);
      printf("%d %d\n", last_a[1], last_a[2 + x]);
    }
  }
}