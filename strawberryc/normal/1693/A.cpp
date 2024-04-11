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

typedef long long ll;

const int N = 2e5 + 5;

int n, a[N];
ll sum[N];

int main() {
  int T; read(T);
  while (T--) {
  	read(n);
  	for (int i = 1; i <= n; i++) read(a[i]);
  	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  	if (sum[n]) {puts("no"); continue;}
  	int m = n; bool is = 1;
  	while (m && !a[m]) m--;
  	for (int i = 1; i < m; i++) if (sum[i] <= 0) {is = 0; break;}
  	puts(is ? "yes" : "no");
  }
  return 0;
}