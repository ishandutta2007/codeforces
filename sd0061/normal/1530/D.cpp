#include <bits/stdc++.h>
const int N = 200005;

int n, a[N], d[N], b[N];
bool tree[N], link[N];

void work() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++i) {
    d[i] = 0;
    tree[i] = 0;
    b[i] = 0;
    link[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++d[a[i]];
  }
  std::queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (!d[i]) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int x = q.front();
    tree[x] = 1;
    q.pop();
    if (!--d[a[x]]) {
      q.push(a[x]);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (tree[i] && !link[a[i]]) {
      b[i] = a[i];
      ++cnt;
      link[a[i]] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!tree[i] && !link[a[i]]) {
      b[i] = a[i];
      ++cnt;
      link[a[i]] = 1;
    }
  }
  std::vector<int> u, v;
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      u.emplace_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!link[i]) {
      v.emplace_back(i);
    }
  }
  if (u.size() == 1 && v.size() == 1 && v[0] == u[0]) {
    for (int i = 1; i <= n; ++i) {
      if (b[i]) {
        b[i] = 0;
        link[b[i]] = 0;
        break;
      }
    }
    --cnt;
  }
  for (int i = 0; i < u.size(); ++i) {
    if (u[i] == v[i]) {
      if (i > 0) {
        std::swap(u[i], u[i - 1]);
      } else if (i + 1 < u.size()) {
        std::swap(u[i], u[i + 1]);
      }
    }
  }

  for (int i = 0; i < u.size(); ++i) {
    b[u[i]] = v[i];
  }

  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", b[i], " \n"[i == n]);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}