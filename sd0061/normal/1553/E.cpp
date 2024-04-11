#include <bits/stdc++.h>
const int N = 300005;

int n, m, a[N], f[N], p[N];

int getf(int x) {
  return f[x] == x ? x : f[x] = getf(f[x]);
}

void work() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  std::map<int, int> off;
  for (int i = 0; i < n; ++i) {
    int x = i;
    int offset = (x - a[x] + n) % n;
    ++off[offset];
  }
  std::vector<std::pair<int, int>> v;
  for (auto [o, c] : off) {
    v.emplace_back(-c, o);
  }
  std::sort(v.begin(), v.end());
  std::vector<int> res;
  for (int k = 0; k < 100 && k < v.size(); ++k) {
    int offset = v[k].second;

    for (int i = 0; i < n; ++i) {
      p[i] = (a[i] + offset) % n;
      f[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      f[getf(i)] = getf(p[i]);
    }
    int cnt = n;
    for (int i = 0; i < n; ++i) {
      if (getf(i) == i) {
        --cnt;
      }
    }
    if (cnt <= m) {
      res.emplace_back(offset);
    }
  }
  printf("%d ", res.size());
  std::sort(res.begin(), res.end());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  puts("");
}

int main() {
  srand(time(0));
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}