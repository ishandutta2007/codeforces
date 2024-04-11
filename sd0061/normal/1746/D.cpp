#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;
int n, k, a[N], s[N], mx[N], cnt[N], c[N];
std::vector<std::vector<int>> e;
std::vector<std::vector<std::pair<int, int>>> v;

int64 res = 0;

void dfs(int x, int sum, int w) {
  sum += a[x];
  s[x] = sum;
  mx[x] = sum;
  res += 1LL * a[x] * w;
  if (e[x].empty()) {
    v[x].emplace_back(mx[x], x);
    return;
  }
  int d = w / e[x].size();
  cnt[x] = w % e[x].size();
  c[x] = w;
  for (auto &y : e[x]) {
    dfs(y, sum, d);
    mx[x] = std::max(mx[x], mx[y]);
  }
  for (auto &y : e[x]) {
    v[x].emplace_back(mx[y], y);
  }
  std::sort(v[x].begin(), v[x].end(), std::greater<std::pair<int, int>>());
}


int DFS(int x) {
  if (e[x].empty()) {
    return a[x];
  }
  std::vector<std::pair<int, int>> w;
  for (auto &y : e[x]) {
    w.emplace_back(DFS(y), y);
  }
  std::sort(w.begin(), w.end());
  std::reverse(w.begin(), w.end());
  for (int i = 0 ; i < cnt[x] ; ++ i) {
    res += w[i].first;
  }
  return a[x] + w[cnt[x]].first;
}

void work() {
  scanf("%d%d", &n, &k);
  e.clear();
  e.resize(n + 1);
  v.clear();
  v.resize(n + 1);
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    e[x].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    mx[i] = 0;
    cnt[i] =0;
  }
  res = 0;
  dfs(1, 0, k);
  DFS(1);
  printf("%lld\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    // static int ca = 0;
    // printf("Case #%d: ", ++ ca);
    work();
  }
  return 0;
}