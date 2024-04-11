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

bool judge(int u, int v) {
  if (u > v) return 0;
  if (u == v) return 1;
  for (int T = 0, cur = 0; T <= 29; T++) {
  	cur += (u >> T) & 1;
  	if ((v >> T) & 1) {
  	  if (cur <= 0) return 0;
  	  cur--;
	}
  }
  return 1;
}

int main() {
  int x, y, q; read(q);
  while (q--) {
  	read(x); read(y);
  	puts(judge(x, y) ? "YES" : "NO");
  }
  return 0;
}