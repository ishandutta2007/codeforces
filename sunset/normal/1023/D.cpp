#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), l(m, n), r(m, -1);
  l[0] = 0;
  r[0] = n - 1;
  int p = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    if (~a[i]) {
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    } else {
      p = i;
    }
  }
  for (int i = m - 1; ~i; --i) {
    if (l[i] > r[i]) {
      if (~p) {
        l[i] = r[i] = p;
      } else {
        puts("NO");
        return 0;
      }
    } else {
      p = l[i];
    }
  }
  vector<int> b(n), f(n + 1);
  for (int i = 0; i <= n; ++i) {
    f[i] = i;
  }
  auto find = [&](int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  };
  for (int i = m - 1; ~i; --i) {
    for (int x = find(l[i]); x <= r[i]; x = find(x)) {
      b[x] = i;
      f[find(x)] = find(x + 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (~a[i] && a[i] != b[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
    printf("%d%c", b[i] + 1, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}