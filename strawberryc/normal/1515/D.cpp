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

int n, l, r, c[N], cntl[N], cntr[N];

void work() {
  int ans = 0;
  read(n); read(l); read(r);
  for (int i = 1; i <= n; i++) read(c[i]), cntl[i] = cntr[i] = 0;
  if (l < r) {
  	std::swap(l, r);
  	for (int i = 1; i <= n / 2; i++) std::swap(c[i], c[n - i + 1]);
  }
  int m = l - r >> 1;
  for (int i = 1; i <= l; i++) cntl[c[i]]++;
  for (int i = n; i > l; i--) cntr[c[i]]++;
  for (int i = 1; i <= n; i++) if (cntl[i] > cntr[i]) {
  	int d = cntl[i] - cntr[i] >> 1;
  	if (d > m) d = m;
  	cntl[i] -= d; cntr[i] += d; m -= d;
  }
  for (int i = 1; i <= n; i++) if (m && cntl[i] > cntr[i])
    m--, cntl[i]--, cntr[i]++;
  for (int i = 1; i <= n; i++) ans += abs(cntl[i] - cntr[i]);
  printf("%d\n", (ans + l - r) / 2);
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}