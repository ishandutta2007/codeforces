#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, s, m, k;
  scanf("%d %d %d %d", &n, &s, &m, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<pair<int, int>> segments(s);
  for (int i = 0; i < s; ++i) {
    scanf("%d %d", &segments[i].first, &segments[i].second);
    --segments[i].first;
    --segments[i].second;
    segments[i].second = -segments[i].second;
  }
  sort(segments.begin(), segments.end());
  vector<pair<int, int>> seg;
  for (int i = 0; i < s; ++i) {
    segments[i].second = -segments[i].second;
    if (seg.empty() || segments[i].second > seg.back().second) {
      seg.push_back(segments[i]);
    }
  }
  s = seg.size();
  m = min(m, s);
  auto check = [&](int bound) {
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + (a[i] <= bound);
    }
    vector<int> f(s), g(s), value(s);
    for (int use = 0; use < m; ++use) {
      deque<int> q;
      for (int i = 0, j = 0, best = 0; i < s; ++i) {
        while (seg[j].second < seg[i].first) {
          best = max(best, g[j]);
          if (q.front() == j) {
            q.pop_front();
          }
          ++j;
        }
        f[i] = best + sum[seg[i].second + 1] - sum[seg[i].first];
        if (!q.empty()) {
          f[i] = max(f[i], sum[seg[i].second + 1] + value[q.front()]);
        }
        value[i] = g[i] - sum[seg[i].second + 1];
        while (!q.empty() && value[q.back()] <= value[i]) {
          q.pop_back();
        }
        q.push_back(i);
      }
      g = f;
    }
    return *max_element(f.begin(), f.end()) >= k;
  };
  if (!check(1e9)) {
    puts("-1");
  } else {
    int l = 1, r = 1e9;
    while (l < r) {
      int mid = l + r >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", r);
  }
  return 0;
}