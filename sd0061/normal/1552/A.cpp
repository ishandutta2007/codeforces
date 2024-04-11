#include <bits/stdc++.h>
using int64 = long long;

void work() {
  int n;
  std::string s, t;
  std::cin >> n >> s;
  t = s;
  std::sort(t.begin(), t.end());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += (s[i] != t[i]);
  }
  printf("%d\n", res);
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}