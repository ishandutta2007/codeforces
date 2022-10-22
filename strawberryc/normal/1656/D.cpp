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

ll n;

void yhjssa() {
  read(n); ll p2 = 1;
  while (!(n & 1)) p2 <<= 1, n >>= 1;
  if (n == 1) return (void) puts("-1");
  printf("%lld\n", std::min(p2 << 1, n));
}

int main() {
  int T; read(T);
  while (T--) yhjssa();
  return 0;
}