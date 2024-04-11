#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}

int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
  return x;
}

int mul(int x, int y) {
  return (long long)x * y % md;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  --m;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }
  sort(p.begin(), p.end());
  vector<int> prev(n), next(n);
  for (int i = 0; i < n; ++i) {
    prev[i] = i - 1;
    next[i] = i + 1;
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    int x = p[i].second, left = x - prev[x], right = next[x] - x, coef = md - 1;
    int ways_left = left / m, ways_right = right / m;
    int limit_left = left % m, limit_right = right % m;
    coef = add(coef, mul(ways_left + (limit_left > 0), ways_right + (limit_right > 0)));
    if (!limit_left) {
      ++limit_left;
    }
    if (!limit_right) {
      ++limit_right;
    }
    limit_right = m - limit_right + 1;
    coef = add(coef, mul(min(limit_left, limit_right) - 1, mul(ways_left + 1, ways_right)));
    coef = add(coef, mul(m - max(limit_left, limit_right), mul(ways_left, ways_right + 1)));
    coef = add(coef, mul(max(limit_right - limit_left, 0), mul(ways_left, ways_right)));
    coef = add(coef, mul(max(limit_left - limit_right, 0), mul(ways_left + 1, ways_right + 1)));
    answer = add(answer, mul(coef, p[i].first));
    if (~prev[x]) {
      next[prev[x]] = next[x];
    }
    if (next[x] != n) {
      prev[next[x]] = prev[x];
    }
  }
  printf("%d\n", answer);
  return 0;
}