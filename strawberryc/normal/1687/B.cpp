#include <bits/stdc++.h>

const int N = 1e4 + 5;

int n, m, a[N], l[N], ans;
char s[N];

int query() {
  printf("? ");
  for (int i = 1; i <= m; i++) putchar(s[i]);
  puts(""); fflush(stdout);
  int ans; scanf("%d", &ans);
  return ans;
}

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) a[i] = i;
  for (int i = 1; i <= m; i++) {
  	for (int j = 1; j <= m; j++) s[j] = j == i ? '1' : '0';
  	l[i] = query();
  }
  std::sort(a + 1, a + m + 1, [&](int x, int y)
    {return l[x] < l[y];});
  for (int i = 1; i <= m; i++) s[i] = '0';
  for (int i = 1; i <= m; i++)
    if (s[a[i]] = '1', query() < ans + l[a[i]])
      s[a[i]] = '0';
    else ans += l[a[i]];
  return printf("! %d\n", ans), 0;
}