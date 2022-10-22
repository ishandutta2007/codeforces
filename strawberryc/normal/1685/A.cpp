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

const int N = 1e5 + 5;

int n, a[N], ans[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	std::sort(a + 1, a + n + 1);
  	if (n & 1) {puts("NO"); continue;}
  	bool res = 1;
  	for (int i = 1, cur; i <= n; i++) {
  	  if (i == 1 || a[i] > a[i - 1]) cur = 1;
  	  else cur++;
  	  if (cur > n / 2 || (cur == n / 2 && i != n / 2 && i != n))
		res = 0;
	}
	puts(res ? "YES" : "NO");
	if (res) {
	  for (int i = 1; i <= n / 2; i++) ans[i * 2 - 1] = a[i];
	  for (int i = 1; i <= n / 2; i++) ans[i * 2] = a[i + n / 2];
	  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	  puts("");
	}
  }
  return 0;
}