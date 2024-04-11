#include <bits/stdc++.h>

template <class T>
inline void read(T &res) {
  res = 0; bool bo = 0; char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-');
  if (c == '-') bo = 1; else res = c - 48;
  while ((c = getchar()) >= '0' && c <= '9')
    res = (res << 3) + (res << 1) + (c - 48);
  if (bo) res = ~res + 1;
}

const int N = 2e5 + 5;

int n, x, a[N];
std::map<int, int> orz;

void yhjssa() {
  int ans = 0;
  read(n); read(x);
  for (int i = 1; i <= n; i++) read(a[i]);
  std::sort(a + 1, a + n + 1);
  orz.clear();
  for (int i = 1; i <= n; i++)
    if (a[i] % x || !orz[a[i] / x]) orz[a[i]]++;
    else ans++, orz[a[i] / x]--;
  printf("%d\n", n - ans * 2);
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}