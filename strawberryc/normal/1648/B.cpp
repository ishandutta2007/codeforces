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

const int N = 1e6 + 5;

int n, c, a[N], sum[N];

void yhjssa() {
  int x;
  read(n); read(c);
  for (int i = 1; i <= c; i++) a[i] = 0;
  while (n--) read(x), a[x]++;
  for (int i = 1; i <= c; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= c; i++) if (!a[i])
    for (int j = 1; i * j <= c; j++) {
      if (!a[j]) continue;
      int l = i * j, r = (i + 1) * j - 1;
      if (r > c) r = c;
      if (sum[r] > sum[l - 1]) return (void) puts("No");
	}
  puts("Yes");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}