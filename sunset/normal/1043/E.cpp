#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
  }
  vector<vector<int>> adj(n);
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<long long> answer(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&](int x, int y) {
    return a[x] - a[y] < b[x] - b[y];
  });
  long long sum;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    answer[p[i]] += (long long)i * b[p[i]] + sum;
    sum += a[p[i]];
  }
  sum = 0;
  for (int i = n - 1; ~i; --i) {
    answer[p[i]] += (long long)(n - i - 1) * a[p[i]] + sum;
    sum += b[p[i]];
  }
  for (int i = 0; i < n; ++i) {
    for (auto j : adj[i]) {
      answer[i] -= min(a[i] + b[j], a[j] + b[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", answer[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}