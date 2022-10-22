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

int n, q, a[N], cnt1;

int main() {
  int op, x;
  read(n); read(q);
  for (int i = 1; i <= n; i++) read(a[i]), cnt1 += a[i];
  while (q--) {
  	read(op); read(x);
  	if (op == 1) {
  	  if (a[x]) cnt1--; else cnt1++;
  	  a[x] ^= 1;
	}
	else printf("%d\n", x <= cnt1);
  }
  return 0;
}