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

int n, a[N], ans;

void yhjssa() {
  ans = 0;
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int T = 0; T < 30; T++) {
  	int cnt = 0;
  	for (int i = 1; i <= n; i++) cnt += (a[i] >> T) & 1;
  	ans = std::__gcd(ans, cnt);
  }
  for (int i = 1; i <= n; i++) if (ans % i == 0) printf("%d ", i);
  puts("");
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}