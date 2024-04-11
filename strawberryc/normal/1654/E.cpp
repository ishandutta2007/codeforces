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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = N << 1;

int n, a[N], b[N], ans = 1, ToT, vis[M], cnt[M];

int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  if (n == 1) return puts("0"), 0;
  for (int d = -100; d <= 100; d++) {
  	for (int i = 1; i <= n; i++) b[i] = a[i] - d * i;
  	std::sort(b + 1, b + n + 1);
  	for (int i = 1, c; i <= n; i++)
  	  ans = Max(ans, c = i > 1 && b[i] == b[i - 1] ? c + 1 : 1);
  }
  for (int i = 1; i <= n; i++) {
  	ToT++;
    for (int j = i + 1; j <= n && j - i <= 1002; j++) {
      if ((a[j] - a[i]) % (j - i)) continue;
      int z = (a[j] - a[i]) / (j - i) + 100000;
      if (vis[z] < ToT) vis[z] = ToT, cnt[z] = 1; else cnt[z]++;
      ans = Max(ans, cnt[z] + 1);
	}
  }
  return std::cout << n - ans << std::endl, 0;
}